class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mod = 12345;
        vector<vector<int>> ans(m, vector<int>(n));
        int suf = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                ans[i][j] = suf;
                suf = (1LL*suf%mod * grid[i][j]%mod)%mod;
            }
        }
        int pre = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = (1LL*pre%mod * ans[i][j]%mod)%mod;
                pre = (1LL*pre * grid[i][j]%mod)%mod;
            }
        }
        return ans;
    }
};