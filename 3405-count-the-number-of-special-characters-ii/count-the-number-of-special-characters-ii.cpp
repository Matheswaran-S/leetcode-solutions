class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> caps(26,0), small(26, 0);
        for(auto c : word){
            int val = c - 'a';
            if(val >= 0 && val < 26){
                small[val] = 1;
                if(caps[val] == 1){
                    small[val] = 2;
                }
            }
            else caps[c - 'A'] = 1;
        }
        int ans = 0;
        for(int i=0; i<26; i++) if(small[i] == caps[i] && caps[i] == 1) ans++;
        return ans;
    }
};