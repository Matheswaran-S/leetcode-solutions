class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j, int mask, vector<vector<vector<int>>> &dp){
        if(i == 0 && j == 0){
            return mask;
        }
        if(dp[i][j][mask] != -1) return dp[i][j][mask];
        int up = INT_MAX;
        if(i-1 >= 0) up = dfs(grid, i-1, j, mask^grid[i-1][j], dp);
        int l = INT_MAX;
        if(j-1 >= 0) l = dfs(grid, i, j-1, mask^grid[i][j-1], dp);
        return dp[i][j][mask] = min(up, l);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return dfs(grid, m-1, n-1, grid[m-1][n-1], dp);
    }
};