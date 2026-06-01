class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(), ans = 0;
        sort(cost.begin(), cost.end());
        for(int i=n-1; i>=0; ){
            ans += cost[i];
            i--;
            if(i >= 0) ans += cost[i];
            i -= 2;
        }
        return ans;
    }
};