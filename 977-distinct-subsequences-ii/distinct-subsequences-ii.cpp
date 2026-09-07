#define mod 1000000007
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26,-1), prev(n,-1);
        for(int i=0; i<n; i++){
            prev[i] = last[s[i]-'a'];
            last[s[i]-'a'] = i; 
        }
        vector<int> dp(n+1);
        dp[0] = 1;
        long long tot,dup=0;
        for(int i=0; i<n; i++){
            tot = ((dp[i]%mod) * (2%mod))%mod;
            if(prev[i] != -1) dup = dp[prev[i]]%mod;
            dp[i+1] = ((tot%mod) - (dup%mod) + mod)%mod;
            dup = 0;
        }
        return (dp[n]-1+mod)%mod;
    }
};