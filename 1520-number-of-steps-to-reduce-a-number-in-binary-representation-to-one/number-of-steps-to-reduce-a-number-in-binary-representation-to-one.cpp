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
            if(car == '0' && s[i] == '0'){
                ans++;
            }
            else if(car == '0' && s[i] == '1'){
                car = '1';
                ans += 2;
            }
            else if(car == '1' && s[i] == '0'){
                car = '1';
                ans += 2;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};