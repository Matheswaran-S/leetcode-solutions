class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n = nums.size();
        vector<int> pre(n+1, -1);
        vector<int> suf(n+1, -1);
        int l = 0, r = 0, sum = 0;
        while(r < n){
            sum += nums[r];
            if(r - l + 1 == s){
                pre[r+1] = max(sum , pre[r]);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        l = n-1 , r = n-1 , sum = 0;
        while(l >= 0){
            sum += nums[l];
            if(r - l + 1 == s){
                suf[l] = max(suf[l+1], sum);
                sum -= nums[r];
                r--;
            }
            l--;
        }
        l = 0, r = 0, sum = 0;
        int ans = 0;
        while(r < n){
            sum += nums[r];
            if(r - l + 1 == f){
                if(l >= s) ans = max(ans, sum+pre[l]);
                if(n - r > s) ans = max(ans, sum+suf[r+1]);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};