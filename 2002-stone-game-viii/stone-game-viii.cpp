class Solution {
public:
    int f(int i, vector<int> &pre, int n, unordered_map<int,int> &dp){
        if(i == n-1) return pre[i];
        if(dp.find(i) != dp.end()) return dp[i];
        int take = pre[i] - f(i+1, pre, n, dp);
        int nt = f(i+1, pre, n, dp);
        return dp[i] = max(take, nt);
    }
    int stoneGameVIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for(int i=1; i<n; i++) pre[i] = pre[i-1]+nums[i];
        unordered_map<int,int> dp;
        return f(1,pre,n, dp);
    }
};