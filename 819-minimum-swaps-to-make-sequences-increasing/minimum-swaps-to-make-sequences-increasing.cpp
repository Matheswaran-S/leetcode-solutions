class Solution {
public:
    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int s, vector<vector<int>> &dp){
        if(i==0){
            if(!s){
                if(nums1[i]<nums1[i+1] && nums2[i]<nums2[i+1]) return 0;
                else return 1;
            }
            else{
                if(nums1[i]<nums2[i+1] && nums2[i]<nums1[i+1]) return 0;
                else return 1;
            }
        }
        if(dp[i][s] != -1) return dp[i][s];

        int dont = INT_MAX;
        if(s){
            if(nums1[i]<nums2[i+1] && nums2[i]<nums1[i+1]){
                dont = dfs(nums1, nums2, i-1, 0, dp);
            }
        }
        else{
            if(nums1[i]<nums1[i+1] && nums2[i]<nums2[i+1]){
                dont = dfs(nums1, nums2, i-1, 0, dp);
            }
        }
        
        int swp = INT_MAX;
        if(s){
            if(nums2[i]<nums2[i+1] && nums1[i]<nums1[i+1]){
                swp = 1+dfs(nums1, nums2, i-1, 1, dp);
            }
        }
        else{
            if(nums2[i]<nums1[i+1] && nums1[i]<nums2[i+1]){
                swp = 1+dfs(nums1, nums2, i-1, 1, dp);
            }
        }
        return dp[i][s] = min(dont,swp);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return min(dfs(nums1, nums2, n-2, 0, dp),1+dfs(nums1,nums2,n-2,1,dp));
    }
};