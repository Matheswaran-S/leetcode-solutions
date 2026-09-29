class Solution {
public:
    bool f(vector<vector<char>> &grid, int i, int j, int m, int n, int c, vector<vector<vector<int>>> &dp){
        if(i == m-1 && j == n-1){
            if(c == 0) return true;
            return false;
        }
        if(dp[i][j][c] != -1) return dp[i][j][c];
        bool d = false, r = false;
        if(i+1 < m){
            int off = (grid[i+1][j] == ')')? -1 : 1;
            if(c+off >= 0) d = f(grid, i+1, j, m, n, c+off, dp);
        }
        if(j+1 < n){
            int off = (grid[i][j+1] == ')')? -1 : 1;
            if(c+off >= 0) r = f(grid, i, j+1, m, n, c+off, dp);
        }
        return dp[i][j][c] = d || r;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][0] == ')') return false;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(201, -1)));
        return f(grid, 0, 0, m, n, 1, dp);
    }
};