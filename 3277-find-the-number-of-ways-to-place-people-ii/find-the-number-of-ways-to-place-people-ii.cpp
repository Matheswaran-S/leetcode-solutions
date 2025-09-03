class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        for(int i=0; i<n; i++) points[i][1] = -points[i][1];
        sort(points.begin(),points.end());
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            int x = points[i][0], y = -points[i][1], ymax = INT_MIN;
            for(int j = i+1; j<n; j++){
                int x1 = points[j][0], y1 = -points[j][1];
                if(y1 <= y && y1 > ymax){
                    cnt++;
                    ymax = y1;
                }
            }
        }
        return cnt;
    }
};