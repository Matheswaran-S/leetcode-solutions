class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int n = apple.size(), m = capacity.size();
        int sum = 0,cnt = 0, ans = 0;
        for(int i=0; i<n; i++) sum += apple[i];
        for(int i=m-1; i>=0; i--){
            if(cnt < sum){
                cnt += capacity[i];
                ans++;
            }
            else return ans;
        }
        return ans;
    }
};