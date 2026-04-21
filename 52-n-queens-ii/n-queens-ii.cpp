class Solution {
private:
    bool check(int i, int j, vector<bool>& cols, vector<bool> &diag1, vector<bool> &diag2, int n){
        if(cols[j]) return false;
        if(diag1[i+n-j]) return false;
        if(diag2[i+j]) return false;
        return true;
    }
    int rec(vector<string> &ds, int n, int i, vector<bool>& cols, vector<bool> &diag1, vector<bool> &diag2){
        if(i == n){
            return 1;
        }

        int c = 0;
        for(int j=0; j<n; j++){
            if(check(i,j,cols,diag1,diag2,n)){
                ds[i][j] = 'Q';
                cols[j] = true;
                diag1[i+n-j] = true;
                diag2[i+j] = true;
                c += rec(ds, n, i+1, cols, diag1, diag2);
                ds[i][j] = '.';
                cols[j] = false;
                diag1[i+n-j] = false;
                diag2[i+j] = false;
            }
        }
        return c;
    }
public:
    int totalNQueens(int n) {
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
        return rec(ds, n, 0, cols, diag1, diag2);
    }
};