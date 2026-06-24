class Solution {
public:
    int f(vector<int> &nums, int i, int sum, int target, map<pair<int,int>,int> &dp){
        if(i == 0){
            if(sum+nums[i] == target && sum-nums[i] == target) return dp[{i,sum}] = 2;
            else if(sum+nums[i] == target || sum-nums[i] == target) return dp[{i,sum}] = 1;
            else return dp[{i,sum}] = 0;
        }
        if(dp.find({i,sum}) != dp.end()) return dp[{i,sum}];
        return dp[{i,sum}] = f(nums, i-1, sum-nums[i], target, dp)+f(nums, i-1, sum+nums[i], target, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>,int> dp;
        return f(nums, n-1, 0, target, dp);
    }
};