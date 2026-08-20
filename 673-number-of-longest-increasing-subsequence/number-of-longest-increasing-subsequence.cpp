class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), cnts(n,1);
        int mxl = 1, ans = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        cnts[i] = cnts[j];
                    }
                    else if(dp[i] == dp[j]+1){
                        cnts[i] += cnts[j];
                    }
                }
            }
            if(dp[i] > mxl){
                mxl = dp[i];
                ans = cnts[i];
            }
            else if(dp[i] == mxl){
                ans += cnts[i];
            }
        }
        return ans;
    }
};