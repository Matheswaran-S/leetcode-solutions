class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int l = 0, r = matrix[0].size()-1, u = 0, d = matrix.size()-1;
        while(l<=r && u<=d){
            if(u<=d){
                for(int i=l;i<=r;i++){
                    v.push_back(matrix[u][i]);
                }
                u++;
            }
            if(l<=r){
                for(int i=u;i<=d;i++){
                    v.push_back(matrix[i][r]);
                }
                r--;
            }
            if(d>=u){
                for(int i=r; i>=l; i--){
                    v.push_back(matrix[d][i]);
                }
                d--;
            }
            if(l<=r){
                for(int i=d; i>=u; i--){
                    v.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return v;
    }
};