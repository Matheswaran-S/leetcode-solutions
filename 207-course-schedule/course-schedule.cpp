class Solution {
    private:
        bool dfs(int u, vector<int> adj[], vector<bool> &vis, vector<bool> &path)
        {
            vis[u] = true;
            path[u] = true;
            for (auto &v: adj[u])
            {
                if (!vis[v]){
                    if(dfs(v, adj, vis, path)) return true;
                }
                else if(path[v]) return true;
            }
            path[u] = 0;
            return false;
        }
    public:
        bool canFinish(int n, vector<vector < int>> &prerequisites)
        {
            vector<int> adj[n];
            for (int i = 0; i < prerequisites.size(); i++)
            {
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
            vector<bool> vis(n, 0);
            vector<bool> path(n, 0);
            for (int i = 0; i < n; i++)
            {
                if(!vis[i]) if (dfs(i, adj, vis, path)) return false;
            }
            return true;
        }
        
};