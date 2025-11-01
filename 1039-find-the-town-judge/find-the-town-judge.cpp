class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;
        if(trust.size() == 0) return -1;
        vector<int> v(n+1, 1);
        v[0] = 0;
        for(int i=0; i<trust.size(); i++){
            v[trust[i][0]] = 0;
            v[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++){
            if(v[i] == n) return i;
        }
        return -1;
    }
};