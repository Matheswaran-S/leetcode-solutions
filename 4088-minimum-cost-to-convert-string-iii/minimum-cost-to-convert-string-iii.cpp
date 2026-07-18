class Solution {
public:
    long long rec(int i, string &source, string &target, vector<vector<string>>& rules, vector<int>& costs, vector<long long> &dp){
        if(i == source.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int res = INT_MAX;
        if(source[i] == target[i]) res = 0 + rec(i+1, source, target, rules, costs, dp);
            for(int r=0; r<rules.size(); r++){
                string pat = rules[r][0], rep = rules[r][1]; 
                bool use = true;
                if(i+rep.size() > source.size()) use = false;
                if(use){
                    for(int l=i; l<i+rep.size(); l++){
                        if(target[l] != rep[l-i]){
                            use = false;
                            break;
                        }
                    }
                }
                if(use){
                    bool doa = true;
                    int ast = 0;
                    for(int l=i; l<i+rep.size(); l++){
                        if((pat[l-i] != '*') && (source[l] != pat[l-i])){
                            doa = false;
                            break;
                        }
                        else if(pat[l-i] == '*') ast++;
                    }
                    if(doa) res = min(1LL*res, costs[r]+ast+rec(i+rep.size(), source, target, rules, costs, dp));
                }
            }
        return dp[i] = res;
    }
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size(), m = target.size();
        if(n != m) return -1;
        vector<long long> dp(n, -1);
        int ans = rec(0, source, target, rules, costs, dp);
        return ans >= INT_MAX ? -1 : ans;
    }
};