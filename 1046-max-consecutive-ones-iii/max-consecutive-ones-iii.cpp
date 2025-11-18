class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), maxi = 0, z = 0;
        while(r < n){
            if(nums[r] == 0) z++;
            if(z > k){
                if(nums[l] == 0) z--;
                l++;
            }
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};