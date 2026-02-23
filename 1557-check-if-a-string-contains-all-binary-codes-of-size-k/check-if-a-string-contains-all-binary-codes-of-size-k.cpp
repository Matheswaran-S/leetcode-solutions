class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int cnt = 0;
        unordered_map<string, bool> mpp;
        int l=0, r=0, n = s.size();
        string t;
        while(r < n){
            if(r-l+1 == k){
                t = s.substr(l,k);
                if(!mpp[t]){
                    cnt++;
                }
                mpp[t] = true;
                l++;
            }
            r++;
        }
        if(cnt == (1<<k)) return true;
        return false;
    }
};