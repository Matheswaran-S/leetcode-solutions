class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 0;
        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int sz = 0, tot = 0;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    sz++;
                    tot += adj[u].size();
                    for(auto &v : adj[u]){
                        if(!vis[v]){
                            vis[v] = 1;
                            q.push(v);
                        }
                    }
                }
                if((sz*(sz-1))/2 == tot/2) ans++;
            }
        }
        return ans;
    }
};