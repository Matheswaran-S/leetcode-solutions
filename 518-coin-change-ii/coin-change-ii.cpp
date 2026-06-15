class Solution {
public:
    int f(int i, int amt, vector<int> &coins, vector<vector<int>> &dp){
        if(i == -1) return 0;
        if(amt == 0) return dp[i][amt] = 1;
        if(dp[i][amt] != -1) return dp[i][amt];

        int ans = 0;
        if(amt - coins[i] >= 0) ans += f(i, amt-coins[i], coins, dp);
        ans += f(i-1, amt, coins, dp);

        return dp[i][amt] = ans;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins, dp);
    }
};