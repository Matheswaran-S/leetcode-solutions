#define ll long long
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        ll l=0, r=0, cur = 0;
        while(l < n){
            cur += nums[r%n];
            if(r-l+1 == n/2){
                ans += (cur > (sum-cur));
                cur -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};