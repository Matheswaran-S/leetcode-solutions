class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> z;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    z.push_back({i,j});
                }
            }
        }
        for(auto it : z){
            int i = it.first;
            int j = it.second;
            for(int r=0; r<matrix[i].size(); r++){
                if(matrix[i][r] != 0){
                    matrix[i][r] = 0;
                }
            }
            for(int l=0; l<matrix.size(); l++){
                if(matrix[l][j] != 0){
                    matrix[l][j] = 0;
                }
            }
        }
    }
};