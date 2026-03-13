#define ll long long
class Solution {
public:
    long long check(ll mid, vector<int> &nums, int h, vector<ll> &sum, int n){
        ll maxi = 0;
        for(int i=0; i<n; i++){
            ll src = mid/nums[i] + 1;
            auto it = lower_bound(sum.begin(), sum.end(), src);
            int ind = (it-sum.begin())-1;
            if(ind < 0) return 0;
            maxi = max(maxi, sum[ind]*nums[i]);
            h -= ind;
            if(h <= 0) return maxi;
        }
        if(h <= 0) return maxi;
        return 0;
    }
    long long minNumberOfSeconds(int h, vector<int>& nums) {
        ll lo = 1, hi = 1e18, n = nums.size(), ans = 1e18;
        vector<ll> sum(1e5+1, 0);
        for(ll i=1; i<=1e5; i++){
            sum[i] = i*(i+1)/2;
        }
        while(lo <= hi){
            ll mid = lo+(hi-lo)/2;
            ll val = check(mid, nums, h, sum, n);
            if(val){
                ans = val;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};