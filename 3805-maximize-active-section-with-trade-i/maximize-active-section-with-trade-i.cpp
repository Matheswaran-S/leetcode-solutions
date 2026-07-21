class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), prev = -1, cur = 0, cnt = 0, mx = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                cnt++;
                if(cur > 0){
                    prev = cur;
                    cur = 0;
                }
            }
            else if(s[i] == '0'){
                cur++;
                if(prev != -1) mx = max(mx, prev+cur);
            }
        }
        return cnt+mx;
    }
};