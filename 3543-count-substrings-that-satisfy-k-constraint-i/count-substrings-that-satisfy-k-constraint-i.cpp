class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int z = 0, o = 0, cnt = 0, n = s.size(),l = 0, r = 0;
        while(r < n){
            if(s[r] == '1') o++;
            else if(s[r] == '0') z++;
            while(o > k && z > k){
                if(s[l] == '0') z--;
                else o--;
                l++; 
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
};