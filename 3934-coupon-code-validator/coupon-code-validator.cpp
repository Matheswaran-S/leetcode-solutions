class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string,string>> ans;
        for(int i=0; i<n; i++){
            bool c=1, b = 1, a=1;
            if(code[i].size() == 0) c=0;
            for(int j=0; j<code[i].size(); j++){
                if(code[i][j]-'a' >= 0 && code[i][j]-'a'<26 || code[i][j]-'A' >= 0 && code[i][j]-'A'<26 || code[i][j]-'0' >= 0 && code[i][j]-'0'<10 || code[i][j] == '_') continue;
                else{
                    c=0;
                    break;
                }
            }
            if(!c) continue;
            if(businessLine[i] != "electronics" && businessLine[i] != "grocery" && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant") b=0;
            if(a && b && isActive[i] == true) ans.push_back({businessLine[i],code[i]});
        }
        sort(ans.begin(), ans.end());
        vector<string> res;
        for(auto &i : ans) res.push_back(i.second);
        return res;
    }
};