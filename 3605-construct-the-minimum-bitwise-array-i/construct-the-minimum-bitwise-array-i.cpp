class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] == 2) ans.push_back(-1);
            else if((nums[i]+1 & nums[i]) == 0) ans.push_back(nums[i]>>1);
            else{
                for(int j=1; j<31; j++){
                    if((nums[i] & (1<<j)) == 0){
                        ans.push_back(nums[i] - (1<<j-1));
                        break;
                    }
                }
            }
            /*
            1011 - 11 - 1001+1010
            1101 - 13 - 1100+1101
            1011110001 - 1011110000
            1011110011 - 1011110001
            101111 - 100111+
            */
        }
        return ans;
    }
};