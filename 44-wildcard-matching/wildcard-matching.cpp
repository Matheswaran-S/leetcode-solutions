class Solution {
public:
    bool rec(int i, int j, string &s, string &p, vector<vector<int>> &dp, vector<bool> &cont){
        if(i == -1 && (j == -1 || cont[j])) return true;
        if(j < 0 || i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(p[j] == '?'){
            ans = rec(i-1,j-1,s,p,dp,cont);
        }
        else if(p[j] == '*'){
            ans = ans || rec(i,j-1,s,p,dp,cont) || rec(i-1,j,s,p,dp,cont) || rec(i-1,j-1,s,p,dp,cont);
        }
        else{
            if(s[i] == p[j]) ans = rec(i-1,j-1,s,p,dp,cont);
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> cont(n,false);
        for(int i=0; i<n; i++){
            if(p[i] == '*') cont[i] = true;
            else break;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(m-1, n-1, s, p, dp, cont);
    }
};