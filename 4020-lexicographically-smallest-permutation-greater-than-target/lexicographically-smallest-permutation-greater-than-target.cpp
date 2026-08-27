class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int n = s.size();
        sort(s.rbegin(), s.rend());
        if(s <= t) return "";
        vector<int> f(26, 0);
        for(auto &c : s) f[c-'a']++;
        string ans;
        bool edge = true;
        for(int i=0; i<n; i++){
            bool put = false;
            for(int j=0; j<26; j++){
                if(!edge && f[j]){
                    ans += 'a'+j;
                    f[j]--;
                    put = true;
                    break;
                }
                if(f[j] && j == t[i]-'a'){
                    ans += t[i];
                    f[j]--;
                    put = true;
                    break;
                }
                else if(f[j] && j > t[i]-'a'){
                    edge = false;
                    ans += (char)'a'+j;
                    f[j]--;
                    put = true;
                    break;
                }
            }
            if(!put) break;
        }
        if(!edge) return ans;
            bool found = false;
            for(int i=ans.size()-1; i>=0; i--){
                f[ans[i]-'a']++;
                for(int j=0; j<26; j++){
                    if(f[j] && j > t[i]-'a'){
                        ans[i] = 'a'+j;
                        f[ans[i]-'a']--;
                        found = true;
                        break;
                    }
                }
                if(found) break;
                ans.pop_back();
            }
            for(int i=0; i<26; i++){
                while(f[i]--){
                    ans.push_back('a'+i);
                }
            }
            return ans;
        /*cbbbadaaa
        dcbaaabba

        dcbaabaab*/
    }
};