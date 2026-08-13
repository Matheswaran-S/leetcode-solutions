class Solution {
public:
    bool rec(int mask, int tot, int mx, vector<int> &dp){
        if(tot <= 0) return false;
        if(dp[mask] != -1) return dp[mask];
        bool win = true;
        for(int i=1; i<=mx; i++){
            if(!(mask & (1<<(i-1)))){
                if(!rec((mask | (1<<(i-1))), tot-i, mx, dp)){
                    win = false;
                }
                else{
                    if(tot - i <= 0) win = false;
                }
            }
        }
        return dp[mask] = !win;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return false;
        if(desiredTotal <= maxChoosableInteger) return true;
        vector<int> dp(1<<maxChoosableInteger , -1);
        return rec(0, desiredTotal, maxChoosableInteger, dp);
    }
};