class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i=0; i<n; i++){
            intervals[i][0] = -1 * intervals[i][0];
            swap(intervals[i][0], intervals[i][1]);
        }
        sort(intervals.begin(), intervals.end());
        int cnt = 2, prel = intervals[0][0], presl = intervals[0][0]-1;
        for(int i=1; i<n; i++){
            int l = -1 * intervals[i][1];
            cout<<l<<' '<<prel<<' '<<presl;
            if(l > prel){
                cnt += 2;
                prel = intervals[i][0];
                presl = intervals[i][0]-1;
            }
            else if(l > presl){
                cnt++;
                presl = prel;
                prel = intervals[i][0];
            }
        }
        return cnt;
    }
};