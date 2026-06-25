class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0;
        vector<int> pre(n, 0);
        pre[0] = nums[0] == target? 1 : 0;
        for(int i=1; i<n; i++){
            if(nums[i] == target) pre[i] = pre[i-1] + 1;
            else pre[i] = pre[i-1];
        }
        for(int r=0; r<n; r++){
            int cnt = pre[r];
            for(int l=max(r - (2*cnt-1)+1, 0); l<=r; l++){
                int sub = 0;
                if(l == 0) sub = cnt;
                else sub = cnt - pre[l-1];
                if(sub > (r-l+1)/2) ans++;
            }
        }
        return ans;
    }
};