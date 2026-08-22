class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>> mpp;
        int n = text.size();
        text[0] = tolower(text[0]);
        string s;
        for(int i=0; i<n; i++){
            if(text[i] == ' '){
                mpp[s.size()].push_back(s);
                s = "";
            }
            else{
                s += text[i];
            }
        }
        if(s.size()){
            mpp[s.size()].push_back(s);
            s = "";
        }
        string ans;
        for(auto &[k,v] : mpp){
            for(auto &st : v){
                ans += (st + ' ');
            }
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};