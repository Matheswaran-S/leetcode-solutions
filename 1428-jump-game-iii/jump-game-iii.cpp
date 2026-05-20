class Solution {
public:
    int f(int i, vector<int> &arr, vector<int> &dp){
        cout<<i<<' '<<dp[i];
        if(arr[i] == 0) return 1;
        if(dp[i] != -1) return dp[i];
        dp[i] = 0;
        int left = 0, right = 0;
        if((i - arr[i]) >= 0) left = f(i-arr[i], arr, dp);
        if((i + arr[i]) < arr.size()) right = f(i+arr[i], arr, dp);
        return dp[i] = (left | right); 
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(start, arr, dp);
    }
};