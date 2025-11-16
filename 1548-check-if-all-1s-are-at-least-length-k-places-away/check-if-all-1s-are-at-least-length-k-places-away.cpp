class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int l = -1, r = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                l = r;
                r = i;
                if(l > -1 && r > -1){
                    if(r-l-1 < k) return false;
                }
            }
        }
        return true;
    }
};