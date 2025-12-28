class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 0, m = grid[0].size();
        for(int i=0; i<n; i++){
            int low = 0, high = m-1;
            while(low <= high){
                int mid = (low+high)/2;
                if(grid[i][mid] >= 0) low = mid+1;
                else if(grid[i][mid] < 0) high = mid-1;
            }
            cnt += (m-low);
        }
        return cnt;
    }
};