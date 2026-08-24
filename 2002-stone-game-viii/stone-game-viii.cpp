class Solution {
public:
    int stoneGameVIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for(int i=1; i<n; i++) pre[i] = pre[i-1]+nums[i];
        vector<int> dp(n);
        dp[n-1] = pre[n-1];
        for(int i=n-2; i>=1; i--) dp[i] = max(dp[i+1], pre[i]-dp[i+1]);
        return dp[1];
    }
};