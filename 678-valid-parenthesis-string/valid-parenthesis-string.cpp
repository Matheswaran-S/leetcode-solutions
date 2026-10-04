class Solution {
public:
    bool f(string &s, int i, int cnt, int n, vector<vector<int>> &dp){
        if(i == n){
            if(cnt == 0) return true;
            return false;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        bool ans = false;
        if(s[i] == '('){
             ans = f(s, i+1, cnt+1, n, dp);
        }
        else if(s[i] == ')'){
            if(cnt-1 >= 0)  ans = f(s, i+1, cnt-1, n, dp);
        }
        else{
            ans = ans || f(s, i+1, cnt+1, n, dp);
            if(cnt-1 >= 0) ans = ans || f(s, i+1, cnt-1, n, dp);
            ans = ans || f(s, i+1, cnt, n, dp);
        }
        return dp[i][cnt] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(101, -1));
        return f(s, 0, 0, n, dp);
    }
};