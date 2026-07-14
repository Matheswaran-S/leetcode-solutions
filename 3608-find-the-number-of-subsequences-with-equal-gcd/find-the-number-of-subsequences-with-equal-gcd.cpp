#define mod 1000000007
class Solution {
public:
    int f(vector<int> &nums, int i, int seq1, int seq2, vector<vector<vector<int>>> &dp){
        if(i == nums.size()){
            if(seq1 != 0 && seq2 != 0 && seq1 == seq2) return 1;
            return 0;
        }
        if(dp[i][seq1][seq2] != -1) return dp[i][seq1][seq2];
        int skip = f(nums, i+1, seq1, seq2, dp);
        int s1 = f(nums, i+1, __gcd(seq1, nums[i]), seq2, dp);
        int s2 = f(nums, i+1, seq1, __gcd(seq2, nums[i]), dp);
        return dp[i][seq1][seq2] = (((skip%mod + s1%mod)%mod + s2%mod)%mod);
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (201, vector<int>(201, -1)));
        return f(nums, 0, 0, 0, dp);
    }
};