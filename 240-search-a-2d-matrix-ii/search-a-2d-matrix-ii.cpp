class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++){
            if(target > matrix[i][n-1] || target < matrix[i][0]) continue;
            for(int j=0; j<n; j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};