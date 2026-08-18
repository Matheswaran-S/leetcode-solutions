class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        for(int i=0; i<n; i++) arrivalTime[i] = arrivalTime[i]%period;
        int maxl = *max_element(lights.begin(), lights.end());
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(arrivalTime[i] < maxl) ans = max(ans, 0);
            else ans = max(ans, period - arrivalTime[i]);
        }
        return ans;
    }
};