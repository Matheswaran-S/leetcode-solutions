class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<n1; i++) mpp[s1[i]]++;
        for(int i=0; i<=n2-n1; i++){
            unordered_map<char,int> ref;
            int j = i;
            bool ok = true;
            while(j < i+n1){
                ref[s2[j]]++;
                if(ref[s2[j]] > mpp[s2[j]]){
                    ok = false;
                }
                j++;
                if(!ok) break;
            }
            if(ok) return true;
        }
        return false;
    }
};