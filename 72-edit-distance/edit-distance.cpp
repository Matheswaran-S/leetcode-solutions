class Solution {
public:
    int rec(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i==-1 && j==-1) return 0;
        else if(i==-1) return j+1;
        else if(j==-1) return i+1;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = rec(word1,word2,i-1,j-1,dp);
        else{
            return dp[i][j] = min(1+rec(word1, word2, i, j-1, dp),min(1+rec(word1, word2, i-1, j, dp),1+rec(word1, word2, i-1, j-1, dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m , -1));
        return rec(word1, word2, n-1, m-1, dp);
    }
};