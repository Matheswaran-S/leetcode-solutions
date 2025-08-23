class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /* 1432 - 2431 - 2134*/
        int n = nums.size();
        if(n < 3){
            if(n == 2) {swap(nums[0],nums[1]); return;}
        }
        else{
            int l = n-2, r = n-1;
            while(l >= 0){
                if(nums[l+1] > nums[l]) break;
                l--;
            }
            while(r > l && l >= 0){
                if(nums[r] > nums[l]) {swap(nums[r],nums[l]);break;}
                r--;
            }
            l++;
            r = n-1;
            while(l<r){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
        }
    }
};