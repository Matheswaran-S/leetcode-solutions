class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size(), max1 = 0, max2 = 0;
        for(int i=0; i<n; i++){
            if(abs(nums[i]) >= max1){
                max2 = max1;
                max1 = abs(nums[i]);
            }
            else max2 = max(max2, abs(nums[i]));
        }
        return (long long)max1*max2*100000;
    }
};