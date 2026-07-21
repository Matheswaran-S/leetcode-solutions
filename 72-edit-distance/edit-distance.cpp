class Solution {
public:
    int rec(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return 0;
        else if(i==0) return j;
        else if(j==0) return i;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]) return dp[i][j] = rec(word1,word2,i-1,j-1,dp);
        else{
            return dp[i][j] = min(1+rec(word1, word2, i, j-1, dp),min(1+rec(word1, word2, i-1, j, dp),1+rec(word1, word2, i-1, j-1, dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1));
        return rec(word1, word2, n, m, dp);
    }
};