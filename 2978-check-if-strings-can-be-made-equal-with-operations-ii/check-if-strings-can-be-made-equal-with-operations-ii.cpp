class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> odd(26,0), even(26,0);
        int n = s1.size();
        for(int i=0; i<n; i++){
            if(i&1) odd[s2[i]-'a']++;
            else even[s2[i]-'a']++;
        }
        for(int i=0; i<n; i++){
            if(i&1){
                if(odd[s1[i]-'a'] > 0) odd[s1[i]-'a']--;
                else return false;
            }
            else{
                if(even[s1[i]-'a']>0) even[s1[i]-'a']--;
                else return false;
            }
        }
        return true;
    }
};