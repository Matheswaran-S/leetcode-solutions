class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int,char>> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '(') st.push({i,'('});
            if(s[i] == ')'){
                if(!st.empty() && st.top().second == '(') st.pop();
                else st.push({i,s[i]});
            }
        }
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            s[p.first] = '#';
        }
        string ans;
        for(int i=0; i<n; i++){
            if(s[i] == '#') continue;
            ans += s[i];
        }
        return ans;
    }
};