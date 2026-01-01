class Solution {
private:
    bool dfs(int r, int c, int row, int col, vector<vector<int>> &vis){
        if(r < 0 || r >= row || c < 0 || c >= col || vis[r][c]) return false;
        vis[r][c] = 1;
        if(r == row-1) return true;
        if(dfs(r+1, c, row, col, vis)) return true;
        if(dfs(r-1, c, row, col, vis)) return true;
        if(dfs(r, c+1, row, col, vis)) return true;
        if(dfs(r, c-1, row, col, vis)) return true;
        return false;
    }
    bool fill(vector<vector<int>> cells, int n, int m, int row, int col){
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for(int i=0; i<m; i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            vis[x][y] = 1;
        }
        for(int i=0; i<col; i++){
            if(dfs(0, i, row, col, vis)) return true;
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row*col;
        int low = 0, high = n-1, day = 0;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(fill(cells, n, mid, row, col)){
                day = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return day;
    }
};