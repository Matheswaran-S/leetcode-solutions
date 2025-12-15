class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sm = 0, la = 0;
        for(int i=0; i<k; i++){
            sm += nums[i];
            la += nums[n-i-1];
        }
        return abs(sm - la);
    }
};