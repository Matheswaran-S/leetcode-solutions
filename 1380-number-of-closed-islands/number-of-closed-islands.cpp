int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int m, int n){
        if(i<0 || i>=m || j<0 || j >= n || grid[i][j] == 1) return;
        grid[i][j] = 1;
        for(int k=0; k<4; k++) dfs(i+dx[k], j+dy[k], grid, m, n);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(),ans=0;
        for(int i=0; i<m; i++){
            if(grid[i][0] == 0) dfs(i,0,grid,m,n);
            if(grid[i][n-1] == 0) dfs(i,n-1,grid,m,n);
        }
        for(int j=0; j<n; j++){
            if(grid[0][j] == 0) dfs(0,j,grid,m,n);
            if(grid[m-1][j] == 0) dfs(m-1,j,grid,m,n);
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(i,j,grid,m,n);
                }
            }
        }
        return ans;
    }
};