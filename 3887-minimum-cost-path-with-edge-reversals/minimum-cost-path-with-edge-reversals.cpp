class Solution {
private:
    void djikstra(vector<vector<pair<int,int>>> &adj, vector<long long> &dist){
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int w = node.first;
            int u = node.second;
            for(auto &i : adj[u]){
                int v = i.first;
                int wi = i.second;
                if(dist[v] > w+wi){
                    dist[v] = w+wi;
                    pq.push({dist[v], v});
                }
            }
        }
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<long long> dist(n,1e18);
        dist[0] = 0;
        djikstra(adj, dist);
        return dist[n-1] == 1e18 ? -1 : dist[n-1];
    }
};