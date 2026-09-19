class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int orange = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({{i,j},0});
                if(grid[i][j] == 1) orange++;
            }
        }
        int t = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        while(!q.empty()){
            int x = q.front().first.first, y = q.front().first.second;
            int lvl = q.front().second;
            q.pop();
            t = max(t, lvl);
            for(int i=0; i<4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx >=0 && ny>=0 && nx<m && ny<n && grid[nx][ny] == 1 && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny},lvl+1});
                    orange--;
                }
            }
        }
        if(orange) return -1;
        return t;
    }
};