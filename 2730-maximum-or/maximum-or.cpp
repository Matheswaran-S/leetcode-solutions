class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> suf(n+1, 0);
        for(int i=n-1; i>=0; i--) suf[i] = suf[i+1] | nums[i];
        long long pre = 0, ans = 0;
        for(int i=0;i<n; i++){
            ans = max(ans, pre | ((nums[i]*1LL)<<k) | suf[i+1]);
            pre |= nums[i];
        }
        return ans;
    }
};