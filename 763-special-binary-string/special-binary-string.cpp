class Solution {
private:
    string rec(int l, int r, string &s){
        if(l == r) return "";
        vector<string> res;
        int cnt = 0;
        for(int i=l; i<=r; i++){
            cnt += s[i] == '1' ? 1 : -1;
            if(cnt == 0){
                res.push_back('1'+rec(l+1, i-1, s)+'0');
                l = i+1;
            }
        }
        sort(res.rbegin(), res.rend());
        string t = "";
        for(auto &i : res) t += i;
        return t;
    }
public:
    string makeLargestSpecial(string s) {
        return rec(0,s.size()-1, s);
    }
};