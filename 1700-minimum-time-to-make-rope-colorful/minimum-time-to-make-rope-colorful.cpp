class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), maxi = neededTime[0], sum = 0;
        if(n == 1) return 0;
        for(int i=1; i<n; i++){
            if(colors[i] == colors[i-1]){
                sum += min(maxi, neededTime[i]);
                if(neededTime[i] >= maxi){
                    maxi = neededTime[i];
                }
            }
            else maxi = neededTime[i];
        }
        return sum;
    }
};