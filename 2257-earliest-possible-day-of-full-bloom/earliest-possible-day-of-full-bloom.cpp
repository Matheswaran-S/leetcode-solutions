class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({growTime[i],plantTime[i]});
        }
        int ans = 0, sft = 0;
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            sft += tp.second;
            ans = max(ans, sft+tp.first);
        }
        return ans;
    }
};