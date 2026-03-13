#define ll long long
class Solution {
private:
    ll fun(ll n){
        ll temp = n;
        vector<int> v;
        while(temp)
        {
            v.push_back(temp%10);
            temp = temp/10;
        }
        reverse(v.begin(), v.end());
        int i=0;
        while(n < 1000000000){
            n *= 10;
            n += v[i];
            i = (i+1)%v.size();
        }
        return n;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<pair<ll,int>> arr(n);
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                arr[i].first = 0;
                arr[i].second = i;
            }
            else{
                ll val = fun(nums[i]);
                arr[i].first = val;
                arr[i].second = i;
            }
        }
        sort(arr.rbegin(), arr.rend());
        string ans;
        for(int i=0; i<n; i++){
            int idx = arr[i].second;
            ans += to_string(nums[idx]);
            if(i==0 && ans[0] == '0') break;
        }
        return ans;
    }
};