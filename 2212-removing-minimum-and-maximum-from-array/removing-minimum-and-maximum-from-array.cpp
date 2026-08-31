class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN, imin = -1, imax = -1, n = nums.size();
        for(int i=0; i<n; i++){
            if(mn > nums[i]){
                mn = nums[i];
                imin = i;
            }
            if(mx < nums[i]){
                mx = nums[i];
                imax = i;
            }
        }
        int mini = min(imax, imin), maxi = max(imax, imin);
        return min({maxi+1, n - mini, mini+1+n-maxi});
    }
};