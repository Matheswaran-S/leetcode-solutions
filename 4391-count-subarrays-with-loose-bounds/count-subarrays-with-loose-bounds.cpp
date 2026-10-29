class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long n = nums.size(), l = 0, r = 0, cnt = 0;
        while(r < n){
            if(nums[r] > maxK || nums[r] < minK){
                l = r+1;
                r++;
                continue;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};