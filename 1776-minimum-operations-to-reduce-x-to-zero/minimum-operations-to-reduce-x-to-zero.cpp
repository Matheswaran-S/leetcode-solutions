class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int tar = sum - x;
        if(tar < 0) return -1;
        int s = 0, l = 0, r = 0, ans = -1;
        while(r < n){
            s += nums[r];
            while(s > tar){
                s -= nums[l];
                l++;
            }
            if(s == tar) ans = max(ans, r-l+1);
            r++;
        }
        return (n-ans > n)? -1 : n-ans;
    }
};