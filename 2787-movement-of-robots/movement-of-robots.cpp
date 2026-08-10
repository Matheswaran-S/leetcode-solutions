#define mod 1000000007
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = s.size();
        vector<long long> val(n), dist(n, 0);
        long long tot = 0;
        for(int i=0; i<n; i++) val[i] = 1LL*nums[i]+ 1LL*((s[i] == 'R')? d : -d);
        sort(val.begin(), val.end());
        for(int i=1; i<n; i++){
            dist[i] = (dist[i-1] + (((val[i]-val[i-1])%mod) * (i%mod))%mod)%mod;
            tot = (tot + dist[i])%mod;
        }
        return tot;
    }
};