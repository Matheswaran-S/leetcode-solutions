#define ll long long
#define mod 1000000007
class Solution {
public:
    int numberOfWays(string s) {
        ll ans = 0;
        int cnts = 0, cntp = 0, n = s.size();
        if(count(s.begin(), s.end(), 'S')%2 != 0) return 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'P') n--;
            else break;
        }
        for(int i=0; i<n; i++){
            if(s[i] == 'S'){
                if(cnts == 2){
                    cnts = 0;
                    if(!ans){
                        ans = 1;
                    }
                    ans = (ans%mod)*(cntp%mod)%mod;
                    cntp = 0;
                }
                cnts++;
                if(cnts == 2) cntp++;
            }
            else{
                if(cnts == 2) cntp++;
            }
        }
        if(cnts == 2){
            if(!ans) ans = 1;
            ans *= 1;
        }
        return ans%mod;
    }
};