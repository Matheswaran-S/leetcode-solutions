class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, indeg(n, 0);
        for(auto &edge : edges){
            indeg[edge[1]]++;
        }
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};