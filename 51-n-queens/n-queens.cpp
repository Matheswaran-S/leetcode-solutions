class Solution {
private:
    bool check(int i, int j, vector<bool>& cols, vector<bool> &diag1, vector<bool> &diag2, int n){
        if(cols[j]) return false;
        if(diag1[i+n-j]) return false;
        if(diag2[i+j]) return false;
        return true;
    }
    void rec(vector<vector<string>> &ans, vector<string> &ds, int n, int i, vector<bool>& cols, vector<bool> &diag1, vector<bool> &diag2){
        if(i == n){
            ans.push_back(ds);
            return;
        }

        for(int j=0; j<n; j++){
            if(check(i,j,cols,diag1,diag2,n)){
                ds[i][j] = 'Q';
                cols[j] = true;
                diag1[i+n-j] = true;
                diag2[i+j] = true;
                rec(ans, ds, n, i+1, cols, diag1, diag2);
                ds[i][j] = '.';
                cols[j] = false;
                diag1[i+n-j] = false;
                diag2[i+j] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds;
        vector<bool> cols(n, false);
        vector<bool> diag1(n+n, false);
        vector<bool> diag2(n+n, false);
        for(int i=0; i<n; i++){
            string t = "";
            for(int j=0; j<n; j++){
                t += '.';
            }
            ds.push_back(t);
        }
        rec(ans, ds, n, 0, cols, diag1, diag2);
        return ans;
    }
};