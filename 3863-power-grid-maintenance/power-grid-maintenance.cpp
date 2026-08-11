class Solution {
private:
    void dfs(vector<int> adj[], int u, unordered_map<int,set<int>*> &mpp, set<int> &s, vector<bool> &vis){
        vis[u] = true;
        s.insert(u);
        mpp[u] = &s;
        for(auto &it : adj[u]){
            if(!vis[it]) dfs(adj, it, mpp, s, vis);
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& edge, vector<vector<int>>& queries) {
        vector<int> adj[c+1];
        int n = edge.size();
        for(int i=0; i<n; i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        unordered_map<int,set<int>*> mpp;
        vector<bool> vis(c+1, 0);
        for(int i=1; i<=c; i++){
            if(!vis[i]){
                set<int>* st = new set<int>();
                dfs(adj, i, mpp, *st, vis);
                (*st).insert(INT_MAX);
                //for(auto &it : *st) cout<<it;
            }
            cout<<endl;
        }
        vector<bool> on(c+1, 1);
        vector<int> res;
        for(int i=0; i<queries.size(); i++){
            int op = queries[i][0], u = queries[i][1];
            if(op == 1){
                if(on[u]) res.push_back(u);
                else{
                    if(*((*mpp[u]).begin()) == INT_MAX) res.push_back(-1);
                    else res.push_back(*((*mpp[u]).begin()));
                }
            }
            else{
                (*mpp[u]).erase(u);
                on[u] = false;
            }
        }
        return res;;
    }
};