class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++) pq.push({abs(arr[i]-x), arr[i]});
        while(k--){
            int ele = pq.top().second;
            pq.pop();
            ans.push_back(ele);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};