class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), pre = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        for(int i=0; i<n; i++){
            pre = (pre + nums[i])%k;
            if(mpp.find(pre) != mpp.end()){
                if(i - mpp[pre] >= 2) return true;
            }
            else mpp[pre] = i;
        }
        return false;
    }
};