class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        unordered_map<int,int> free;
        vector<vector<int>> next(budget+1, vector<int>(2,0)), cur(budget+1, vector<int>(2, 0));
        for(int i=0; i<n; i++){
            int num = items[i][0];
            for(int j=1; j*j<=num; j++){
                if(num%j == 0){
                    free[j]++;
                    if(j != num/j) free[num/j]++;
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int bud=0; bud<=budget; bud++){
                for(int f=0; f<2; f++){
                    int b = 0;
                    if(items[i][1] <= bud){
                        if(f) b = free[items[i][0]]+cur[bud - items[i][1]][0];
                        else b = 1+cur[bud - items[i][1]][0];
                    }
                    int nb = next[bud][1];
                    cur[bud][f] = max(b, nb);
                }
            }
            next = cur;
        }
        return next[budget][1];
    }
};