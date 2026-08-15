class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        long long xr = 0;
        bool pos = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > 0) pos = 1;
            xr ^= nums[i];
        }
        if(xr) return n;
        else if(pos) return n-1;
        return 0;
    }
};