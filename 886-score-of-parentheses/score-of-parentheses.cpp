class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size(), ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') st.push(-1);
            else{
                int t = 0;
                while(!st.empty() && st.top() != -1){
                    t += st.top();
                    st.pop();
                }
                st.pop();
                st.push(max(2*t, 1));
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};