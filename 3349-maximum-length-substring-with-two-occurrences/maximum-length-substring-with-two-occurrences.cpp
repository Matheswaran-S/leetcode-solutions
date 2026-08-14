class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), l = 0, r = 0, ans = 0;
        vector<int> fre(26, 0);
        while(r<n){
            fre[s[r]-'a']++;
            while(fre[s[r]-'a'] > 2){
                fre[s[l]-'a']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};