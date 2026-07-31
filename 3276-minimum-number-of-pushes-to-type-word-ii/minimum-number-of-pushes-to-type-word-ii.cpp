class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> fre(26, 0);
        for(auto &c : word){
            fre[c - 'a']++;
        }  
        sort(fre.rbegin(), fre.rend());
        int ans = 0;
        for(int i=0; i<26; i++){
            ans += (fre[i]*(i/8 + 1));
        }
        return ans;
    }
};