#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = LLONG_MIN;
        vector<ll> pre(n+1, 0);
        for(int i=0; i<n; i++) pre[i+1] = pre[i]+nums[i];
        unordered_map<ll,ll> mpp;
        for(int i=0; i<n; i++){
            if(mpp.find(nums[i]+k) != mpp.end()){
                ll l = mpp[nums[i]+k];
                ans = max(ans, pre[i+1]-l);
            }
            if(mpp.find(nums[i]-k) != mpp.end()){
                ll l = mpp[nums[i]-k];
                ans = max(ans, pre[i+1]-l);
            }
            if(mpp.find(nums[i]) != mpp.end()){
                mpp[nums[i]] = min(mpp[nums[i]], pre[i]);
            }
            else mpp[nums[i]] = pre[i];
        }
        return (ans == LLONG_MIN)? 0 : ans;
    }
};