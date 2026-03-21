class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> prev(sum+1, 0);
        for(int i=0; i<=sum; i++){
            if(i >= 2*stones[0]) prev[i] = i-2*stones[0];
            else prev[i] = i;
        }
        for(int i=1; i<n; i++){
            for(int j=sum; j>=0; j--){
                int nt = prev[j];
                int t = INT_MAX;
                if(j >= 2*stones[i]) t = prev[j - 2*stones[i]];
                prev[j] = min(t,nt);
            }
        }
        return prev[sum];
    }
};