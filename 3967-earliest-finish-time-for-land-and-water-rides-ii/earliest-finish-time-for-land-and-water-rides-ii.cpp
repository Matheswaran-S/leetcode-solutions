class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l = landStartTime.size(), w = waterDuration.size();
        int minl = INT_MAX, minw = INT_MAX;
        for(int i=0; i<l; i++) minl = min(minl, landStartTime[i]+landDuration[i]);
        for(int i=0; i<w; i++) minw = min(minw, waterStartTime[i]+waterDuration[i]);
        int ans = INT_MAX;
        for(int i=0; i<w; i++){
            if(waterStartTime[i] <= minl) ans = min(ans, minl+waterDuration[i]);
            else ans = min(ans, waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0; i<l; i++){
            if(landStartTime[i] <= minw) ans = min(ans, minw+landDuration[i]);
            else ans = min(ans, landStartTime[i]+landDuration[i]);
        }
        return ans;
    }
};