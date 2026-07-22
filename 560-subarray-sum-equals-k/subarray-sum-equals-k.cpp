class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int pre = 0;
        for(int i=0; i<n; i++){
            pre += nums[i];
            ans += mpp[pre - k];
            mpp[pre]++;
        }
        return ans;
    }
};