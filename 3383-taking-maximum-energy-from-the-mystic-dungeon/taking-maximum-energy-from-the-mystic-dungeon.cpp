class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(k, 0);
        int n = energy.size(), maxi = INT_MIN;
        for(int i=0; i<n; i++){
            dp[i%k] = max(dp[i%k]+energy[i], energy[i]);
            //if(i >= n-k) maxi = max(maxi, energy[i]);
        }
        //return max(maxi,*max_element(dp.begin(), dp.end()));
        return *max_element(dp.begin(), dp.end());
    }
};