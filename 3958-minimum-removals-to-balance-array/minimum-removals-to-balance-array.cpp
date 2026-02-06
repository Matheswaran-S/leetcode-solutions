#define ll long long 
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int l=0, r=0, ans = INT_MIN;
        while(r < n){
            while(nums[r] > 1LL*k*nums[l]){
                l++;
            }
            if(nums[r] <= 1LL*k*nums[l]){
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return n-ans;
    }
};