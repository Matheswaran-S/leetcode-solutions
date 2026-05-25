class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);cout.tie(nullptr);
        int n = nums.size(), pre = nums[0] , suf = nums[n-1];
        for(int i=n-2; i>0; i--){
            suf *= nums[i];
        }
        int z = count(nums.begin(), nums.end(), 0);
        vector<int> ans(n, 0);
        if(z > 1) return ans;
        if(z == 1){
            int prds = 1, ind = -1;
            for(int i=0; i<n; i++){
                if(nums[i] != 0) prds *= nums[i];
                else ind = i;
            }
            ans[ind] = prds;
            return ans;
        }
        ans[0] = suf;
        ans[n-1] = (suf/nums[n-1])*pre;
        for(int i=1; i<n-1; i++){
            suf = suf/nums[i];
            ans[i] = pre*suf;
            pre *= nums[i];
        }
        return ans;
    }
};