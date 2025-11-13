class Solution {
public:
    int maxOperations(string s) {
        int one = 0, n = s.size(), cnt = 0;
        int prev = s[n-1] - '0';
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0') prev = 0;
            else if(s[i] == '1' && prev == 0){
                prev = 1;
                one++;
            }
            if(s[i] == '1') cnt += one;
        }
        return cnt;
    }
};