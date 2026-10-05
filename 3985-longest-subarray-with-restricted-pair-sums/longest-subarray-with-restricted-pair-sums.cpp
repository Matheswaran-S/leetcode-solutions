class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> mpp(501, 0);
        int l=0, r=0;
        while(r < n){
            while(true){
                bool ok = false;
                for(int i=1; i<=500; i++){
                    if(mpp[i] > 0){
                        if(nums[r]-i >= 0 && mpp[nums[r]-i] > 0){
                            if(nums[r]/i == 2){
                                if(mpp[i] > 1){
                                    ok = true;
                                    break;
                                }
                            }
                            else{
                                ok = true;
                                break;
                            }
                        }
                        if(nums[r]+i <= 500 && mpp[nums[r]+i] > 0){
                            ok = true;
                            break;
                        }
                    }
                }
                if(ok){
                    mpp[nums[l]]--;
                    l++;
                }
                else break;
            }
            mpp[nums[r]]++;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};