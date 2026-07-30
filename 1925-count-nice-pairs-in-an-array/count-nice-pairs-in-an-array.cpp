#define ll long long 
#define mod 1000000007
class Solution {
public:
    int rev(int n){
        int t = 0;
        while(n){
            t = t*10 + n%10;
            n /= 10;
        }
        return t;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int diff = nums[i] - rev(nums[i]);
            ans = (ans + mpp[diff]%mod)%mod;
            mpp[diff]++;
        }
        return ans%mod;
    }
};