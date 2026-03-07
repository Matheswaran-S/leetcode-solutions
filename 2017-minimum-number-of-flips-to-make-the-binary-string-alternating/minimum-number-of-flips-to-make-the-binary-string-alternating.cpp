class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int z=0, one = 0;
        for(int i=0; i<n; i++) if(i%2 != s[i]-'0') z++;
        one = n-z;
        int curz = 0, curo = 0, ans = min(z,one);
        if(n%2 == 0) return ans;
        for(int i=0; i<n; i++){
            if(i%2 != s[i]-'0') curz++;
            else curo++;
            ans = min({ans,one-curo+curz, z-curz+curo});
        }  
        return ans;
    }
};