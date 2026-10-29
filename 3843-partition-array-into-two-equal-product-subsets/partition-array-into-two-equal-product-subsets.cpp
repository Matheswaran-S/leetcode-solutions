#define ll long long
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll n = nums.size(), mask = (1<<n)-1, p1 = 1, p2 = 1;
        for(ll i = 1; i<= mask; i++){
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    if(p1*nums[j] > target) break;
                    p1 *= nums[j];
                }
                else{
                    if(p2*nums[j] > target) break;
                    p2 *= nums[j];
                }
                if(j == n-1 && p1 == p2 && p1 == target) return true;
            }
            p1 = 1;
            p2 = 1;
        }
        return false;
    }
};