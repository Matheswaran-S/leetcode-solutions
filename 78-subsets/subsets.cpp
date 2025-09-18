class Solution {
public:
    void rec(vector<vector<int>> &ans, vector<int> &ds, int ind, int n, vector<int> &nums){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        rec(ans, ds, ind+1, n, nums);
        ds.pop_back();
        rec(ans, ds, ind+1, n, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        rec(ans, ds, 0, nums.size(), nums);
        return ans;
    }
};