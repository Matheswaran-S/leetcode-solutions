#define ll long long 
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        /*int l=0, r=n-1;
        while(l <= r){
            if(nums[r] <= k*nums[l]) return n-(r-l+1);
            if((k*nums[l+1] - nums[r]) < (k*nums[l]-nums[r-1])) r--;
            else l++;
        }
        return 1;
        */
        ll ans = n-1;
        for(int i=0; i<n; i++){
            auto it = lower_bound(nums.begin()+i, nums.end(), 1LL*nums[i]*k + 1);
            ans = min(ans, (ll)i+(nums.end()-it));
        }
        return ans;
    }
};