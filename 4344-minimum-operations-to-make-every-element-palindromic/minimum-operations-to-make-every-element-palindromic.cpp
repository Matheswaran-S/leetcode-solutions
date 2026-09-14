#define ll long long
static bool init;
vector<ll> odds, evens;
class Solution {
private:
    ll toll(string &s){
        int n = s.size();
        ll num = 0;
        for(int i=0; i<n; i++){
            num = num*10 + (s[i] - '0');
        }
        //cout<<s<<endl;
        return num;
    }
    void rec(string &s, vector<ll> &odds, vector<ll> &evens, int i, int n){
        if(i >= (n+1)/2){
            if((s[n-1]-'0')%2 == 0) evens.push_back(toll(s));
            else odds.push_back(toll(s));
            return;
        }

        for(int j=0; j<10; j++){
            if(i==0 && j==0) continue;
            s[i] = j+'0';
            s[n-i-1] = j+'0';
            rec(s, odds, evens, i+1, n);
        }
    }
    void fun(vector<ll> &odds, vector<ll> &evens){
        // 0 1 2 3 4 5 6 7 8 9
        if(init) return;
        for(int i=1; i<=10; i++){
            string s(i,' ');
            rec(s, odds, evens, 0, i);
        }
        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        init = true;
    }
public:
    long long minOperations(vector<int>& nums) {
        fun(odds, evens);
        int n = nums.size();
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i]&1){
                auto it = lower_bound(odds.begin(), odds.end(), nums[i]);
                int ind = it - odds.begin();
                ll val1 = odds[ind], val2 = INT_MIN;
                if(ind > 0) val2 = odds[ind-1];
                ans += min((val1-nums[i])/2, (nums[i]-val2)/2);
            }
            else{
                auto it = lower_bound(evens.begin(), evens.end(), nums[i]);
                int ind = it - evens.begin();
                ll val1 = evens[ind], val2 = INT_MIN;
                if(ind > 0) val2 = evens[ind-1];
                ans += min((val1-nums[i])/2, (nums[i]-val2)/2);
            }
        }
        return ans;
    }
};