class Solution {
private:
    string rec(int l, int r, string &s, map<string,string> &mpp){
        if(l == r) return "";
        if(mpp[s.substr(l,r-l+1)] != "") return mpp[s.substr(l,r-l+1)];
        vector<string> res;
        int cnt = 0, j = l;
        for(int i=l; i<=r; i++){
            cnt += s[i] == '1' ? 1 : -1;
            if(cnt == 0){
                res.push_back('1'+rec(l+1, i-1, s, mpp)+'0');
                l = i+1;
            }
        }
        sort(res.rbegin(), res.rend());
        string t = "";
        for(auto &i : res) t += i;
        return mpp[s.substr(j,r-j+1)] = t;
    }
public:
    string makeLargestSpecial(string s) {
        map<string,string> mpp;
        return rec(0,s.size()-1, s, mpp);
    }
};