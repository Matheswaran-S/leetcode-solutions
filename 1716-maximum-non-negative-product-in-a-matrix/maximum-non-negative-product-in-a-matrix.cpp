class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mod = 1e9+7;
        vector<vector<long long>> mini(m, vector<long long>(n)), maxi(m, vector<long long>(n)); 
        mini[0][0] = grid[0][0];
        maxi[0][0] = grid[0][0];
        for(int i=1; i<m; i++){
            maxi[i][0] = maxi[i-1][0] * grid[i][0];
            mini[i][0] = mini[i-1][0] * grid[i][0];
        }
        for(int i=1; i<n; i++){
            maxi[0][i] = maxi[0][i-1] * grid[0][i];
            mini[0][i] = mini[0][i-1] * grid[0][i];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                maxi[i][j] = max(maxi[i-1][j]*grid[i][j] , maxi[i][j-1]*grid[i][j]);
                maxi[i][j] = max(maxi[i][j], max(mini[i-1][j]*grid[i][j] , mini[i][j-1]*grid[i][j]));
                mini[i][j] = min(maxi[i-1][j]*grid[i][j] , maxi[i][j-1]*grid[i][j]);
                mini[i][j] = min(mini[i][j], min(mini[i-1][j]*grid[i][j] , mini[i][j-1]*grid[i][j]));
            }
        }
        int ans = maxi[m-1][n-1]%mod;
        return  (ans < 0)? -1 : ans;
    }
};