class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        int n1 = s.size(), n2 = t.size();
        for(int i = 0; i<n2; i++) mpp[t[i]]++;
        int l = 0, r = 0, cnt = 0, ml = 0, mr = -1, len = INT_MAX;
        string str = "";
        while(l <= r && r < n1){
            if(mpp[s[r]] > 0){
                cnt++;
            }
            mpp[s[r]]--;
            if(cnt == n2){
                if(r-l+1 < len){
                    ml = l;
                    mr = r;
                    len = r-l+1;
                }
            }
            while(cnt == n2){
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                if(r-l+1 < len){
                        ml = l;
                        mr = r;
                        len = r-l+1;
                    }
                l++;
            }
            r++;
        }
        cout<<ml<<mr;
        for(int i=ml; i<=mr; i++) str += s[i];
        return str;
    }
};