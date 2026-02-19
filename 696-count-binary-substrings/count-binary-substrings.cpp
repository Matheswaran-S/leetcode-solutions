class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0, cur = 1, res = 0;
        for(int i=0; i<n; i++){
            if(i < n && s[i] == s[i+1]) cur++;
            else{
                res += min(prev,cur);
                prev = cur;
                cur = 1;
            }
        }
        return res;
    }
};