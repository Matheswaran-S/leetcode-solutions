class Solution {
public:
    string maximumXor(string s, string t) {
        int z = 0, o = 0, n = t.size();
        for(int i=0; i<n; i++){
            if(t[i] == '0') z++;
            else o++;
        }
        string ans;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                if(z){
                    z--;
                    ans += '1';
                }
                else{
                    o--;
                    ans += '0';
                }
            }
            else{
                if(o){
                    o--;
                    ans += '1';
                }
                else{
                    z--;
                    ans += '0';
                }
            }
        }
        return ans;
    }
};