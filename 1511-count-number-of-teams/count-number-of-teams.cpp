class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        int ans = 0;
        for(int i=1; i<n; i++){
            dp[i][0][0] = 1, dp[i][0][1] = 1;
            for(int j=0; j<i; j++){
                if(rating[i] > rating[j]){
                    dp[i][1][1] += dp[j][0][1];
                    dp[i][2][1] += dp[j][1][1];
                }
                if(rating[i] < rating[j]){
                    dp[i][1][0] += dp[j][0][0];
                    dp[i][2][0] += dp[j][1][0];
                }
            }
            ans += (dp[i][2][0] + dp[i][2][1]);
        }
        return ans;
    }
};