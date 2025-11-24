class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> premax(n);
        vector<int> sufmax(n);
        premax[0] = 0;
        for(int i=1; i<n; i++){
            premax[i] = max(premax[i-1], height[i-1]);
        }
        sufmax[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            sufmax[i] = max(sufmax[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += max(min(premax[i],sufmax[i]) - height[i], 0);
        }
        return ans;
    }
};