class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for(auto &it : intervals){
            it[1] = -it[1];
        }
        sort(intervals.begin(), intervals.end());
        int ans = intervals.size(), mx = -1;
        for(auto &it: intervals){
            if(-it[1] <= mx) ans--;
            mx = max(mx, -it[1]);
        }
        return ans;
    }
};