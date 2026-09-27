class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                string t;
                while(!st.empty() && st.top() != '('){
                    t += st.top();
                    st.pop();
                }
                st.pop();
                for(auto &i : t) st.push(i);
            }
            else st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};