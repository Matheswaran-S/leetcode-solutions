class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(rbegin(nums),rend(nums));
        int n=nums.size(), l = 0, r = k-1, mini = INT_MAX;
        while(r < n){
            mini = min(mini, nums[l]-nums[r]);
            l++;
            r++;
        }
        return mini;
    }
};