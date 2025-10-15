class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int k1 = 0,k2 = 1,res = 0, n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                k2++;
                res = max({res, min(k1,k2), k2/2});
            }
            else{
                k1 = k2;
                k2 = 1;
            }
        }
        return max({res, min(k1,k2), k2/2});
    }
};