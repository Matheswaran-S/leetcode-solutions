class Solution {
public:
    int numSteps(string s) {
        char car = '0';
        int n = s.size(), ans = 0;
        for(int i=n-1; i>=0; i--){
            if(i==0){
                if(car == '0') break;
                else{
                    ans++;
                    break;
                }
            }
            if(car == s[i]){
                ans++;
            }
            else{
                car = '1';
                ans += 2;
            }
        }
        return ans;
    }
};