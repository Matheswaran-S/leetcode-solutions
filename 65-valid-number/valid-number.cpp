class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool pm = true, exp = true, dot = true;
        for(int i=0; i<n; i++){
            if(s[i] == '+' || s[i] == '-'){
                if(i == n-1) return false;
                if(pm && (i == 0 || s[i-1] == 'e' || s[i-1] == 'E')){
                    pm = false;
                }
                else return false;
                continue;
            }
            if(s[i] == '.'){
                if((i-1 >= 0 && s[i-1]-'0' >= 0 && s[i-1]-'0' <= 9 && dot) || (i+1 < n && s[i+1]-'0' >= 0 && s[i+1]-'0' <= 9 && dot)){
                    dot = false;
                }
                else return false;
                continue;
            }
            if(s[i] == 'e' || s[i] == 'E'){
                if(i == 0 || i == n-1 || !exp || s[i-1] == '+' || s[i-1] == '-') return false;
                dot = false;
                exp = false;
                pm = true;
                continue;
            }
            if(s[i]-'0' < 0 || s[i]-'0' > 9) return false;
        }
        return true;
    }
};