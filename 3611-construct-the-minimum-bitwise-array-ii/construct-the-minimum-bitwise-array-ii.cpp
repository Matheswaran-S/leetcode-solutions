class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] == 2) ans.push_back(-1);
            else{
                for(int j=1; j<31; j++){
                    if((nums[i] & (1<<j)) == 0){
                        ans.push_back(nums[i] - (1<<j-1));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};