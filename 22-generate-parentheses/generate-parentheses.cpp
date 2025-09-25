class Solution {
public:
    void rec(vector<string> &ans, string &ds, int n, int l, int r){
        if(2*n == l+r){
            ans.push_back(ds);
            return;
        }
        else if(r > l) return;
        else if(l > n) return;
        if(l < n){
            ds.push_back('(');
            rec(ans, ds, n, l+1, r);
            ds.pop_back();
        }
        if(r < n){
            ds.push_back(')');
            rec(ans, ds, n, l, r+1);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       string ds;
       rec(ans, ds, n, 0, 0);
       return ans;
    }
};