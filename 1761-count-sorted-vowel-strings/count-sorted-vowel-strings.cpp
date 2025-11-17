class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 5;
        int pre = 0;
        for(int i=2; i<=n; i++){
            pre += (i*(i-1)/2);
            dp[i] = 5 + (i-1)*4 + (i*(i-1)/2)*3 + pre*2 + dp[i-2];
        }
        return dp[n];
    }
};