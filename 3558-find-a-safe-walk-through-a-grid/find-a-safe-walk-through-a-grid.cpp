class Solution {
public:
    bool rec(vector<vector<int>>& grid, int health, int i, int j, map<tuple<int,int,int>,bool> &dp){
        if(i<0 || j<0 || i>=grid.size() || j >= grid[0].size() || grid[i][j] == 2 || health < 1) return false;

        if(i == grid.size()-1 && j == grid[0].size()-1){
            if(grid[i][j] == 1){
                if(health > 1) return true;
                else return false;
            } 
            return true;
        }

        if(dp.find({i,j,health}) != dp.end()) return dp[{i,j,health}];

        int val = grid[i][j];
        grid[i][j] = 2;
        bool left = rec(grid, health-val, i, j-1, dp);
        bool right = rec(grid, health-val, i, j+1, dp);
        bool up = rec(grid, health-val, i-1, j, dp);
        bool down = rec(grid, health-val, i+1, j, dp);
        grid[i][j] = val;

        return dp[{i,j,health}] = left || right || up || down;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        map<tuple<int,int,int>,bool> dp;
        return rec(grid, health, 0, 0, dp);
    }
};