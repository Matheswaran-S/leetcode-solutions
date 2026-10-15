#define MAX 100000
class Solution {
public:
    int rec(int i, int amt, vector<int> &coins, int n, vector<vector<int>> &dp){
        if(amt == 0) return 0;
        if(i == n) return MAX;
        if(dp[i][amt] != -1) return dp[i][amt];
        int take = MAX;
        if(amt-coins[i] >= 0){
            take = 1+min(rec(i,amt-coins[i],coins,n,dp),rec(i+1,amt-coins[i],coins,n,dp));
        }
        int nt = rec(i+1, amt, coins, n, dp);
        return dp[i][amt] = min(take, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = rec(0,amount, coins, n, dp);
        return (ans >= MAX)? -1 : ans;
    }
};