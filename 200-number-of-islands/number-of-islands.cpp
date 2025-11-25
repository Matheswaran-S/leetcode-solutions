class Solution {
private:
    void dfs(vector<vector<char>>& grid,int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};