class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size(), l = 0, r = k-1, mini = INT_MAX;
        while(r < n){
            mini = min(mini, nums[r]-nums[l]);
            l++;
            r++;
        }
        return mini;
    }
};