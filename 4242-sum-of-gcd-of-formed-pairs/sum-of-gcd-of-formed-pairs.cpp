#define ll long long
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        ll gcdsm = 0, n =nums.size(), mx = LLONG_MIN;
        vector<ll> pregcd(n);
        for(int i=0; i<n; i++){
            mx = max(mx, (ll)nums[i]);
            pregcd[i] = __gcd((ll)nums[i], mx);
        }
        sort(pregcd.begin(), pregcd.end());
        int l=0, r=n-1;
        while(l<r){
            gcdsm += __gcd(pregcd[l], pregcd[r]);
            l++;
            r--;
        }
        return gcdsm;
    }
};