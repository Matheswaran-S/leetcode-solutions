class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>, int> mpp;
        int n = nums.size(), len = 0, par = 0, cxr = 0;
        mpp[{par,cxr}] = -1;
        for(int i=0; i<n; i++){
            cxr ^= nums[i];
            if(nums[i]&1) par++;
            else par--;
            if(mpp.find({par,cxr}) != mpp.end()){
                len = max(len, i-mpp[{par,cxr}]);
            } 
            else mpp[{par,cxr}] = i;
        }
        return len;
    }
};