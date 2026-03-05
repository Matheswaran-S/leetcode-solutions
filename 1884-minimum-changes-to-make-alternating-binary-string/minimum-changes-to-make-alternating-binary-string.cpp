class Solution {
public:
    int op(string &s, int st){
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]-'0' != st) cnt++;
            st = 1-st;
        }
        return cnt;
    }
    int minOperations(string s) {
        return min(op(s,0),op(s,1));
    }
};