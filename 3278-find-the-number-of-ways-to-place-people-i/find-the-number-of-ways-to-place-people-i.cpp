class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
            [](vector<int> &a, vector<int> &b){
                if(a[0] == b[0]) return a[1] < b[1];
                return a[0] > b[0];
            });
        int n = points.size(), cnt  = 0;
        for(int i=0; i<points.size(); i++) cout<<points[i][0]<<' '<<points[i][1]<<' ';
        for(int i = 0; i<n-1; i++){
            int minx = -1, miny = INT_MAX;
            if(points[i][0] >= points[i+1][0] && points[i][1] <= points[i+1][1]){
                cnt++;
                minx = points[i+1][0], miny = points[i+1][1];
            }
            for(int j = i+1; j<n-1; j++){
                if(points[i][0] >= points[j+1][0] && points[i][1] <= points[j+1][1] && !(points[i][0] >= minx && minx >= points[j+1][0] && miny >= points[i][1] && miny <= points[j+1][1])){
                    cnt++;
                    minx = max(minx,points[j+1][0]);
                    miny = min(miny,points[j+1][1]);
                }
            }
        }
        return cnt;
    }
};