class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int u,d,l = y, r = y+k;
        while(l<r){
            u = x,d = x+k-1;
            while(u<d){
                swap(grid[u][l],grid[d][l]);
                u++;
                d--;
            }
            l++;
        }
        return grid;
    }
};