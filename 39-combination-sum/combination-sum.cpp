class Solution {
private:
    void rec(vector<vector<int>> &ans, vector<int> &ds, vector<int> &cand, int target, int sum, int ind){
        if(ind == cand.size()) return;
        if(sum == target){
            ans.push_back(ds);
            return;
        }

        if(sum+cand[ind] <= target){
            sum += cand[ind];
            ds.push_back(cand[ind]);
            rec(ans, ds, cand, target, sum, ind);
            sum -= cand[ind];
            ds.pop_back();
            rec(ans, ds, cand, target, sum, ind+1);
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        rec(ans, ds, candidates, target, 0, 0);
        return ans;
    }
};