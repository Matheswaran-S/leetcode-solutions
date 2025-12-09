#define ll long long
#define mod 1000000007
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        ll cnt = 0;
        unordered_map<int, int> total;
        unordered_map<int, int> prefix;

        for(int i=0; i<n; i++){
            total[nums[i]]++;
        }

        prefix[nums[0]]++;

        for(int i=1; i<n-1; i++){
            if(nums[i] == 0) cnt += (ll)(total[nums[i]*2] - prefix[nums[i]*2] - 1) * (ll)prefix[nums[i]*2];
            else cnt += (ll)(total[nums[i]*2] - prefix[nums[i]*2]) * (ll)prefix[nums[i]*2];
            prefix[nums[i]]++;
        }

        return cnt%mod;
    }
};