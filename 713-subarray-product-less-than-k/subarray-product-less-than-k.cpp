class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size(), cnt = 0;
        int l=0, r=0, p=1;
        while(r < n){
            p *= nums[r];
            while(p >= k){
                p = p/nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};