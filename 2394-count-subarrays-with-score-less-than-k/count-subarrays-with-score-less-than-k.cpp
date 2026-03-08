class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), cnt = 0;
        long long l=0, r=0, p=0;
        while(r < n){
            p += nums[r];
            while(p*(r-l+1) >= k){
                p -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};