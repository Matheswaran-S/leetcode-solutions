class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum = nums[0], n = nums.size();
        mpp[nums[0]] = 1;
        bool nt = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]+1 && nt){
                sum += nums[i];
            }
            else nt = 0;
            mpp[nums[i]]++;
        }
        while(mpp[sum]) sum++;
        return sum;
    }
};