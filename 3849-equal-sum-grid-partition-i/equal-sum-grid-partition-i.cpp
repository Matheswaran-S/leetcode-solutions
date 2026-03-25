#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll tot = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) tot += grid[i][j];
        }
        if(tot&1) return false;
        ll tar = tot/2, row = 0, col = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                row += grid[i][j];
                if(j == n-1 && row == tar) return true;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                col += grid[j][i];
                if(j == m-1 && col == tar) return true;
            }
        }
        return false;
    }
};