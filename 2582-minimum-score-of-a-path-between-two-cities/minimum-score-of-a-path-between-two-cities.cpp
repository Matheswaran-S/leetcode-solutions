class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        queue<int> q;
        vector<pair<int,int>> adj[n+1];
        for(auto &it : roads){
            int u = it[0], v = it[1], d = it[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<bool> vis(n+1, 0);
        vis[1] = 1;
        q.push(1);
        int mn = INT_MAX;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &it : adj[u]){
                int v = it.first;
                int d = it.second;

                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
                
                mn = min(mn, d);
            }
        }
        return mn;
    }
};