#define mod 1000000007
class Solution {
public:
    int dfs(unordered_map<int,vector<int>> &graph, int u, vector<bool> &vis){
        if(vis[u]) return 0;
        vis[u] = 1;
        int mx = 0;
        for(auto &v : graph[u]){
            mx = max(mx, 1+dfs(graph, v, vis));
        }
        return mx;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        for(auto &i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        int n = edges.size();
        vector<bool> vis(n+2, 0);
        int k = dfs(graph, 1, vis)-1, ans = 1;
        for(int i=1; i<=(k-1); i++){
            cout<<ans<<' ';
            ans = (ans * 2)%mod;
        }
        return ans;
    }
};