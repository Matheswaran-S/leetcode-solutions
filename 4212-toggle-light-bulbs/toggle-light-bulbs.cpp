class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> f(101,0);
        int n = bulbs.size();
        for(int i=0; i<n; i++) f[bulbs[i]]++;
        vector<int> res;
        for(int i=1; i<=100; i++) if(f[i]&1) res.push_back(i);
        return res;
    }
};