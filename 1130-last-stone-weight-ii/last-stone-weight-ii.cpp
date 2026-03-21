class Solution {
public:
    int rec(vector<int> &stones, int ind, int sum, vector<vector<int>> dp){
        if(ind == 0){
            if(sum - 2*stones[0] >= 0) return sum-2*stones[0];
            else return sum;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int nt = rec(stones, ind-1, sum, dp);
        int t = INT_MAX;
        if(sum >= 2*stones[ind]) t = rec(stones, ind-1, sum - 2*stones[ind], dp);
        return dp[ind][sum] = min(t,nt);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        for(int i=0; i<=sum; i++){
            if(i >= 2*stones[0]) dp[0][i] = i-2*stones[0];
            else dp[0][i] = i;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=sum; j++){
                int nt = dp[i-1][j];
                int t = INT_MAX;
                if(j >= 2*stones[i]) t = dp[i-1][j - 2*stones[i]];
                dp[i][j] = min(t,nt);
            }
        }
        return dp[n-1][sum];
    }
};