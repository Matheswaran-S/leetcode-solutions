class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        vis[0][0] = 1;
        int x=0, y=0, tx,ty;;
        while(true){
            if(grid[x][y] == 'R'){
                tx = x, ty = y+1;
            }
            else if(grid[x][y] == 'L'){
                tx = x, ty = y-1;
            }
            else if(grid[x][y] == 'U'){
                tx = x-1, ty = y;
            }
            else tx = x+1, ty = y;
            if(tx >= 0 && ty >= 0 && tx < m && ty < n && !vis[tx][ty]){
                x = tx;
                y = ty;
                vis[x][y] = 1;
            }
            else return {x,y};
        }
    }
};