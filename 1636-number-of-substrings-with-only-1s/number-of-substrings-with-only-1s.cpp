#define MOD 1000000007
class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long res = 0, l = -1, r = -1;
        while(l < n){
            for(r=l+1; r<n; r++){
                if(s[r] == '0'){
                    res += ((r-l-1)*(r-l)/2);
                    l = r;
                    break;
                }
            }
            if(r == n){
                res += ((r-l-1)*(r-l)/2);
                break;
            }
        }
        return res%MOD;
    }
};