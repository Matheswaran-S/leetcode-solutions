class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size(), ans = 0, c = 0;
        for(int i=0; i<n; i++){
            c += (s[i] == '(')? 1 : -1;
            if(c < 0){
                ans++;
                c = 0;
            }
        }
        return ans+abs(c);
    }
};