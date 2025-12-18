#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll sum = 0, maxi = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){
            sum += (strategy[i]*prices[i]);
        }
        maxi = sum;
        int l=0, r=0;
        while(r < n){
            int d;
            if(r-l < k/2){
                d = strategy[r] - 0;
            }
            else{
                d = strategy[r] - 1;
            }
            sum -= d*prices[r];
            if(r-l+1 == k){
                cout<<maxi<<endl;
                maxi = max(maxi, sum);
                sum -= (0 - strategy[l])*prices[l];
                l++;
                sum -= prices[l+k/2-1];
            }
            r++;
        }
        return maxi;
    }
};