class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            int x = points[i][0], y = points[i][1];
            pq.push({x*x+y*y , i});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};