class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int midr = 0, midc = n-1;
        while(midr < m && midc >= 0){
            if(matrix[midr][midc] == target) return true;
            else if(matrix[midr][midc] < target) midr++;
            else midc--;
        }
        return false;
    }
};