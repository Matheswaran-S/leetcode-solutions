class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int pre = nums[0];
        ans.push_back(!(pre%5));
        for(int i=1; i<nums.size(); i++){
            pre = ((pre<<1)|nums[i])%5;
            ans.push_back(!(pre%5));
        }
        return ans; 
    }
};