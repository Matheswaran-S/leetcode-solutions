class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), i = 0, j = n-1, ans = 0;
        while(colors[i] == colors[j]){
            i++;
        }
        ans = max(ans, j-i);
        i = 0, j = n-1;
        while(colors[i] == colors[j]) j--;
        ans = max(ans, j-i);
        return ans;
   }
};