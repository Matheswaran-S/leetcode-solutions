class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        int n = s.size(), m = knowledge.size();
        unordered_map<string,string> mpp;
        for(int i=0; i<m; i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                string t;
                i++;
                while(s[i] != ')'){
                    t += s[i];
                    i++;
                }
                cout<<t<<endl;
                if(mpp[t].size()) ans += mpp[t];
                else ans += '?';
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};