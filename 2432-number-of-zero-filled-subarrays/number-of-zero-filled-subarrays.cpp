class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, streak = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                streak++;
                res += streak;
            }
            else streak = 0;
        }
        return res;
    }
};