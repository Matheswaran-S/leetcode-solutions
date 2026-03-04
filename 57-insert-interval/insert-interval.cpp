class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        bool ok = false;
        for(int i=0; i<n; i++){
            if(intervals[i][1] < newInterval[0]) ans.push_back(intervals[i]);
            else if(intervals[i][0] > newInterval[1]){
                if(!ok){
                    ans.push_back(newInterval);
                    ok = true;
                }
                ans.push_back(intervals[i]);
            }
            else{
                if(!ok){
                    ans.push_back(newInterval);
                    ok = true;
                }
                int last = ans.size();
                ans[last-1][0] = min(ans[last-1][0], intervals[i][0]);
                ans[last-1][1] = max(ans[last-1][1], intervals[i][1]);
            }
        }
        if(!ok) ans.push_back(newInterval);
        return ans;
    }
};