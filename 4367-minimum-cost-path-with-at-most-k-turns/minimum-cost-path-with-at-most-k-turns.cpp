class Solution {
private:
    vector<int> dr = {-1,0,+1,0};
    vector<int> dc = {0,-1,0,+1};
    map<pair<int,int>,int> mpp = {
        {{-1, 0}, 1},
        {{0, 1}, 2},
        {{1, 0}, 3},
        {{0, -1}, 4}
    };
    int rec(int r, int c, int pre, vector<vector<int>>& grid, int k, int m, int n, vector<vector<vector<vector<int>>>> &dp){
        if(r == m-1 && c == n-1){
            return grid[r][c];
        }
        if(dp[r][c][pre][k] != -1) return dp[r][c][pre][k];
        int cost = 1000000000;
        for(int i=0; i<4; i++){
            int nr = r+dr[i], nc = c+dc[i];
            if(nr < m && nc < n && nr>=0 && nc>=0){
                int cur = mpp[{dr[i],dc[i]}];
                if(pre == 0){
                    cost = min(cost, grid[r][c] + rec(nr, nc, cur, grid, k, m, n, dp));
                }
                else{
                    if(pre == cur){
                        cost = min(cost, grid[r][c] + rec(nr, nc, cur, grid, k, m ,n, dp));
                    }
                    else{
                        if(k>0) cost = min(cost, grid[r][c] + rec(nr, nc, cur, grid, k-1, m, n, dp));
                    }
                }
            }
        }
        return dp[r][c][pre][k] = cost;
    }
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(n, vector<vector<int>>(5, vector<int>(k+1, -1))));
        int ans = rec(0,0,0,grid,k,m,n, dp);
        return (ans > 100000000)? -1 : ans;
    }
};