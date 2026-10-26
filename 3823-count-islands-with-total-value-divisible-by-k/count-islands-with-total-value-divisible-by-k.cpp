int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, int m, int n){
        if(i>=m || i<0 || j>=n || j<0 || vis[i][j] || !grid[i][j]) return 0;
        vis[i][j] = 1;
        long long sum = grid[i][j];
        for(int k=0; k<4; k++) sum += dfs(i+dx[k], j+dy[k], grid, vis, m, n);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0 || vis[i][j]) continue;
                long long val = dfs(i,j,grid,vis,m,n);
                if(val%k == 0) ans++; 
            }
        }
        return ans;
    }
};