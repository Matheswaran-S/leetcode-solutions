class Solution {
public:
    bool check(int l, int r, vector<vector<int>> &grid, int limit, int n){
        for(int i=0; i<n; i++){
            if(abs(grid[i][l] - grid[i][r]) > limit) return false;
        }
        return true;
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size(), m = grid[0].size(), ans = 1;
        vector<int> dp(m, 1);
        for(int j=1; j<m; j++){
            for(int k=0; k<j; k++){
                if(check(k,j,grid,limit,n)) dp[j] = max(dp[j], dp[k]+1);
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};