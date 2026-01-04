class Solution {
public:
    string largestEven(string s) {
        int n = s.size(), i;
        if(s[n-1] == '2') return s;
        for(i=n-1; i>=0; i--){
            if(s[i] == '2') break;
        }
        return s.substr(0, i+1);
    }
};