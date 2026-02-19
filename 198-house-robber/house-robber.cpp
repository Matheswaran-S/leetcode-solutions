class Solution {
private:
    int rec(int i, vector<int> &nums, vector<int> &dp){
        if(i < 0) return 0;
        if(i == 0) return nums[0];
        if(dp[i] != -1) return dp[i];
        int t = nums[i]+rec(i-2, nums, dp);
        int nt = rec(i-1, nums, dp);
        return dp[i] = max(t,nt);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return rec(n-1, nums, dp);
    }
};