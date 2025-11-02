class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i=0; i<walls.size(); i++){
            grid[walls[i][0]][walls[i][1]] = -1;
        }
        for(int i=0; i<guards.size(); i++){
            grid[guards[i][0]][guards[i][1]] = -1;
        }
        int cnt = 0;
        for(int i=0; i<guards.size(); i++){
            int x = guards[i][0], y = guards[i][1];
            for(int up = y-1; up>=0; up--){
                if(grid[x][up] != -1 && grid[x][up] != 1){
                    cnt++;
                    grid[x][up] = 1;
                }
                if(grid[x][up] == -1) break;
            }
            for(int dw = y+1; dw<n; dw++){
                if(grid[x][dw] != -1 && grid[x][dw] != 1){
                    cnt++;
                    grid[x][dw] = 1;
                }
                if(grid[x][dw] == -1) break;
            }
            for(int l = x-1; l>=0; l--){
                if(grid[l][y] != -1 && grid[l][y] != 1){
                    cnt++;
                    grid[l][y] = 1;
                }
                if(grid[l][y] == -1) break;
            }
            for(int r = x+1; r<m; r++){
                if(grid[r][y] != -1 && grid[r][y] != 1){
                    cnt++;
                    grid[r][y] = 1;
                }
                if(grid[r][y] == -1) break;
            }
        }
        return m*n - (cnt + guards.size() + walls.size());
    }
};