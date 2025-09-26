class Solution {
public:
    void rec(vector<vector<int>> &ans, vector<int> &ds, int n, int k, int ind){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<=n; i++){
            ds.push_back(i);
            rec(ans, ds, n, k, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        rec(ans, ds, n, k, 1);
        return ans;
    }
};