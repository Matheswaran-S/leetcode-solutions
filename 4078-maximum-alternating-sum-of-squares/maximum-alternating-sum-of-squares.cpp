#define ll long long 
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end());
        int l=0, r=n-1;
        ll sum = 0;
        while(l <= r){
            if(l == r) sum += nums[l];
            else sum += nums[r] - nums[l];
            l++; r--;
        }
        return sum;
    }
};