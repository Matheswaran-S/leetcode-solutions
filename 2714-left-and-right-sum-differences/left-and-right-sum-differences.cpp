class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size(), lsum = 0, rsum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            rsum -= nums[i];
            ans[i] = abs(lsum - rsum);
            lsum += nums[i];
        }
        return ans;
    }
};