class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size(), maxi = 0;
        vector<int> suf(n);
        suf[n-1] = events[n-1][2];
        for(int i=n-2; i>=0; i--) suf[i] = max(events[i][2],suf[i+1]);
        for(int i=0; i<n; i++){
            int end = events[i][1], low = i, high = n-1, val = events[i][2], idx = -1;
            maxi = max(maxi, val);
            while(low <= high){
                int mid = (low+high)/2;
                if(events[mid][0] > end){
                    idx = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            if(idx != -1) maxi = max(maxi, val+suf[idx]);
        }
        return maxi;
    }
};