class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), cnt = 0;
        if(s[n-1] == '1') return false;
        s[0] = 'v';
        for(int i=minJump; i<n; i++){
            cnt += (s[i - minJump] == 'v' ? 1 : 0);
            if(i - maxJump > 0 && s[i - maxJump - 1] == 'v') cnt--;  
            if(cnt > 0 && s[i] == '0') s[i] = 'v';
        }
        return s[n-1] == 'v';
    }
};