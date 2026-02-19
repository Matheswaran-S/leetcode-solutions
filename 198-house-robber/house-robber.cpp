class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        for(int i=0; i<n; i++){
            if(i==0) dp[i] = nums[i];
            else{
                int t = nums[i];
                if(i > 1) t += dp[i-2];
                int nt = dp[i-1];
                dp[i] = max(t,nt);
            }
        }
        return dp[n-1];
    }
};