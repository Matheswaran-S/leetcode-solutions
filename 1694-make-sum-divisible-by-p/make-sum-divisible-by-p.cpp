class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = INT_MAX, n = nums.size();
        unordered_map<int,int> mpp;
        int tot = 0, pre = 0;
        for(int i=0; i<n; i++) tot = (tot+nums[i]%p)%p;
        if(tot == 0) return 0;
        mpp[0] = -1;
        for(int i=0; i<n; i++){
            pre = (pre+nums[i]%p)%p;
            if(mpp.find((pre-tot+p)%p) != mpp.end()) ans = min(ans, i-mpp[(pre-tot+p)%p]); 
            mpp[pre] = i;
        }
        if(ans >= n) return -1;
        return ans;
    }
};