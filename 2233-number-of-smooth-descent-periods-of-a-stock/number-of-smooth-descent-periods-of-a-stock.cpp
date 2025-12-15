class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = n;
        int l=0, r=1;
        while(r < n){
            if(prices[r-1] - prices[r] == 1) ans += (r-l);
            else l = r;
            r++;
        }
        return ans;
    }
};