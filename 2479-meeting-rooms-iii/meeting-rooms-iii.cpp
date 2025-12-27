#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<ll> mpp(n,0),cnt(n,0);
        int m = meetings.size();
        ll maxi = 0, time = 0;
        for(int i=0; i<m; i++){
            time = meetings[i][0];
            ll mini = LLONG_MAX;
            int idx = -1;
            for(int j=0; j<n; j++){
                if(mpp[j] <= time){
                    idx = j;
                    break;
                }
                if(mpp[j] < mini){
                    idx = j;
                    mini = mpp[j];
                }
            }
            if(mpp[idx] <= time){
                mpp[idx] = meetings[i][1];
            }
            else{
                time = mpp[idx];
                mpp[idx] += (meetings[i][1] - meetings[i][0]);
            }
            cnt[idx]++;
            maxi = max(maxi, cnt[idx]);
            time++;
        }
        for(int i=0; i<n; i++){
            if(cnt[i] == maxi) return i;
        }
        return 0;
    }
};