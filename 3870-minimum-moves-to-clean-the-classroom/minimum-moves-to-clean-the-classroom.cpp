class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size(), n = grid[0].size();
        map<pair<int,int>,int> mpp;
        int lcnt = 0;
        vector<int> start(2);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'L'){
                    mpp[{i,j}] = lcnt;
                    lcnt++;
                }
                if(grid[i][j] == 'S') start = {i,j};
            }
        }
        int mask = (1<<lcnt);
        vector<vector<vector<vector<bool>>>> vis(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy+1 , vector<bool>(mask, 0))));
        queue<tuple<int,int,int,int,int>> q;
        q.push({start[0],start[1],energy,0,0});
        vis[start[0]][start[1]][energy][0] = 1;
        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};
        while(!q.empty()){
            auto tup = q.front();
            int r = get<0>(tup), c = get<1>(tup);
            int e = get<2>(tup), taken = get<3>(tup), moves = get<4>(tup);
            q.pop();
            if(taken == mask-1) return moves;
            for(int i=0; i<4; i++){
                int nr = r+dr[i], nc = c+dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 'X' && e > 0){
                    int egy = (grid[nr][nc] == 'R')? energy : e-1;
                    int take = taken;
                    if(grid[nr][nc] == 'L'){
                        take = (taken | (1<<mpp[{nr,nc}]));
                    }
                    if(!vis[nr][nc][egy][take]){
                        vis[nr][nc][egy][take] = 1;
                        q.push({nr,nc,egy,take,moves+1});
                    }
                }
            }
        }
        return -1;
    }
};