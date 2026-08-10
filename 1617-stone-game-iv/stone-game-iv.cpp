class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, 0);
        int i=1;
        while(i*i <= n){
            dp[i*i] = 1;
            i++;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                int sqr = j*j;
                if(dp[i-sqr] == 0){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};