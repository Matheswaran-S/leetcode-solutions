#define mod (int)1e9+7
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, pro = 1;
        for(int i=0; i<n; i++) sum += nums[i];
        for(int i=n-1; i>=0; i--){
            sum -= nums[i];
            if(sum == pro) return i;
            if(pro > sum) break;
            pro = pro*nums[i];
        }
        return -1;
    }
};