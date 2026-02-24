class Solution {
private:
    int dfs(vector<int> &nums, long long k, long long num, long long den, int i, map<tuple<int,long long,long long>,int> &dp){
        if(i == nums.size()){
            if(num%den == 0 && num/den == k) return 1;
            return 0;
        }
        if(dp.find({i,num,den}) != dp.end()) return dp[{i,num,den}];
        int m = dfs(nums, k, num*nums[i], den, i+1, dp);
        int d = dfs(nums, k, num, den*nums[i], i+1, dp);
        int l = dfs(nums, k, num, den, i+1, dp);
        return dp[{i,num,den}] = m+d+l;
    }
public:
    int countSequences(vector<int>& nums, long long k) {
        int n = nums.size();
        map<tuple<int,long long,long long>,int> dp;
        return dfs(nums, k, 1LL, 1LL, 0, dp);
    }
};