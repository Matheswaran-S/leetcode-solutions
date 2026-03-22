class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int m = mat.size(), n = mat[0].size();
        bool r1 = 1, r2=1, r3=1, r4=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(tar[i][j] != mat[i][j]) r1 = 0;
                if(tar[i][j] != mat[m-j-1][i]) r2 = 0;
                if(tar[i][j] != mat[n-i-1][m-j-1]) r3 = 0;
                if(tar[i][j] != mat[j][n-i-1]) r4 = 0;
            }
        }
        if(r1 || r2 || r3 || r4) return true;
        return false;
    }
};