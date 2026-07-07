class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({nums1[0]+nums2[0],{0,0}});
        map<pair<int,int>,int> mpp;
        vector<vector<int>> ans;
        while(ans.size() < k){
            auto topq = pq.top();
            pq.pop();
            int i = topq.second.first , j = topq.second.second;
            if(mpp[{i,j}]) continue;
            mpp[{i,j}] = 1;
            ans.push_back({nums1[i], nums2[j]});
            if(i+1 < n1) pq.push({nums1[i+1]+nums2[j],{i+1,j}});
            if(j+1 < n2) pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        return ans;
    }
};