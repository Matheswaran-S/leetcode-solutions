class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> a(26, 0);
        int n = cost.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            a[s[i] - 'a'] += cost[i];
        }
        sort(a.begin(), a.end());
        for(int i=0; i<25; i++) ans += a[i];
        return ans;
    }
};