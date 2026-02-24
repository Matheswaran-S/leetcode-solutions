class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int f=1, n = nums.size(), ans = 0;
        for(int i=0; i<n; i++){
            if((i+1)%6 == 0 && nums[i]&1){
                if(f) ans += nums[i];
                else ans -= nums[i];
            } 
            else if((i+1)%6 == 0 || nums[i]&1){
                f = 1-f;
                if(f) ans += nums[i];
                else ans -= nums[i];
            }
            else{
                if(f) ans += nums[i];
                else ans -= nums[i];
            }
        }
        return ans;
    }
};