class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), one = 0;
        for(auto i: nums){
            if( i == 1) one++;
        }
        if(one) return n-one;
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int prev = nums[i];
            for(int j=i+1; j<n; j++){
                if(__gcd(prev, nums[j]) == 1) ans = min(ans, n+j-i-1);
                prev = __gcd(nums[j], prev);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};