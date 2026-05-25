class Solution {
private:
    void rec(vector<int> &ds, vector<vector<int>> &ans, int k, int n, int s){
        if(k == 0 && n == 0){
            ans.push_back(ds);
            return;
        }
        if(k <= 0 || n <= 0) return;
        for(int i=s; i<10; i++){
            ds.push_back(i);
            rec(ds, ans, k-1, n-i, i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(n > 45) return ans;  
        vector<int> ds;
        rec(ds, ans, k, n, 1);
        return ans;
    }
};