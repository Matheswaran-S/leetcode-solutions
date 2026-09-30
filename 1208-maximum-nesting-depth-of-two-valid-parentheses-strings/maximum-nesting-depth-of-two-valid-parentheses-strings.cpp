class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n,0);
        bool tog = 0;
        for(int i=0; i<n; i++){
            ans[i] = (seq[i] == '(')? tog : !tog;
            tog = !tog;
        }
        return ans;
    }
};