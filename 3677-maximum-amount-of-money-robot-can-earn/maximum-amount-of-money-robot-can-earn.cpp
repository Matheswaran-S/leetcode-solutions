class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3))); 
        if(coins[0][0] < 0){
            dp[0][0][1] = 0;
            dp[0][0][2] = 0;
            dp[0][0][0] = coins[0][0];
        }
        else{
            for(int nor=0; nor<3; nor++) dp[0][0][nor] = coins[0][0];
        }
        for(int j=1; j<n; j++){
            for(int nor=0; nor<3; nor++){
                if(coins[0][j] >= 0 || nor == 0){
                    dp[0][j][nor] = coins[0][j]+dp[0][j-1][nor];
                }
                else{
                    long long t1 = dp[0][j-1][nor-1];
                    long long t3 = coins[0][j]+dp[0][j-1][nor];
                    dp[0][j][nor] = max(t1,t3);
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int nor=0; nor<3; nor++){
                if(coins[i][0] >= 0 || nor == 0){
                    dp[i][0][nor] = coins[i][0]+dp[i-1][0][nor];
                }
                else{
                    long long t2 = dp[i-1][0][nor-1];
                    long long t4 = coins[i][0]+dp[i-1][0][nor];
                    dp[i][0][nor] = max(t2,t4);
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                for(int nor=0; nor<3; nor++){
                    if(coins[i][j] >= 0 || nor == 0){
                        dp[i][j][nor] = max(coins[i][j]+dp[i-1][j][nor],coins[i][j]+dp[i][j-1][nor]);
                    }
                    else{
                        long long t1 = dp[i][j-1][nor-1];
                        long long t3 = coins[i][j]+dp[i][j-1][nor];
                        long long t2 = dp[i-1][j][nor-1];
                        long long t4 = coins[i][j]+dp[i-1][j][nor];
                        dp[i][j][nor] = max(max(t2,t4),max(t1,t3));
                    }
                }
            }
        }
        return dp[m-1][n-1][2];
    }
};