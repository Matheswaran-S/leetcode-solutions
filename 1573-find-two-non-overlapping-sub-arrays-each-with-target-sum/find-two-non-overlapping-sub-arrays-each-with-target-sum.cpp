class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> suf(n+1,n+1);
        int l = n-1, r = n-1, sum = 0;
        while(l>=0){
            sum += arr[l];
            while(sum > target){
                sum -= arr[r];
                r--;
            }
            if(sum == target) suf[l] = min(suf[l+1], r-l+1);
            else suf[l] = suf[l+1];
            l--;
        }
        l = 0, r = 0, sum = 0;
        int len = n+1, ans = INT_MAX;
        while(r<n){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            if(sum == target){
                len = min(len, r-l+1);
            }
            ans = min(ans, len+suf[r+1]);
            r++;
        }
        return (ans > n)? -1 : ans;
    }
};