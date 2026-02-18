class Solution
{
    private:
        int bfs(vector<vector < int>> &matrix, vector<vector<int>> &dp, int m, int n, int i, int j, int u)
        {
            if (i < 0 || i >= m || j < 0 || j >= n) return 0;
            if(dp[i][j] != 0 && matrix[i][j] > u) return dp[i][j];
            if (matrix[i][j] > u)
            {
                int up = 1+bfs(matrix, dp, m, n, i - 1, j, matrix[i][j]);
                int left = 1+bfs(matrix, dp, m, n, i, j - 1, matrix[i][j]);
                int right = 1+bfs(matrix, dp, m, n, i, j + 1, matrix[i][j]);
                int down = 1+bfs(matrix, dp, m, n, i + 1, j, matrix[i][j]);
                dp[i][j] = max({up,right,left,down});
                return dp[i][j];
            }
            else return 0;
        }
    public:
        int longestIncreasingPath(vector<vector < int>> &matrix)
        {
            int maxi = 1, m = matrix.size(), n = matrix[0].size();
            vector<vector<int>> dp(m, vector<int>(n,0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    maxi = max(maxi, bfs(matrix, dp, m, n, i, j, -1));
                }
            }
            return maxi;
        }
};