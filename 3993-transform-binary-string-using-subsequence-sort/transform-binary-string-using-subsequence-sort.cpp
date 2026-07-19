class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> z(n,0), o(n,0);
        int s0 = (s[n-1] == '0'), s1 = (s[0] == '1');
        z[n-1] = (s[n-1] == '0');
        for(int i=n-2; i>=0; i--){
            z[i] = z[i+1] + (s[i] == '0');
            s0 += (s[i] == '0');
        }
        o[0] = (s[0] == '1');
        for(int i=1; i<n; i++){
            o[i] = o[i-1] + (s[i] == '1');
            s1 += (s[i] == '1');
        }
        vector<bool> ans;
        int m = strs.size();
        for(int i=0; i<m; i++){
            string str = strs[i];
            int c0 = 0, c1 = 0;
            if(count(str.begin(), str.end(), '0') > s0 || count(str.begin(), str.end(), '1') > s1){
                ans.push_back(false);
                continue;
            }
            bool res = true;
            for(int j=0; j<n; j++){
                if(str[j] == '1'){
                    if(o[j]-c1 <= 0){
                        res = false;
                        break;
                    }
                    else c1++;
                }
            }
            for(int j=n-1; j>=0; j--){
                if(str[j] == '0'){
                    if(z[j]-c0 <= 0){
                        res = false;
                        break;
                    }
                    else c0++;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};