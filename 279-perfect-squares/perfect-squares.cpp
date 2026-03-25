class Solution {
public:
    int numSquares(int n) {
        vector<int> sqr;
        for(int i=1; i*i<=n; i++){
            sqr.push_back(i*i);
        }
        int m = sqr.size();
        vector<int> prev(n+1,0);
        for(int i=0;i<=n; i++) prev[i] = i;
        for(int i=1; i<m; i++){
            for(int j=1; j<=n; j++){
                int nt = prev[j];
                int t = 100000;
                if(j-sqr[i] >= 0) t = 1+prev[j-sqr[i]];
                prev[j] = min(nt,t);
            }
        }
        return prev[n];
    }
};