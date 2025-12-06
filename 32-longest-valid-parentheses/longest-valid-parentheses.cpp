class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        int open = 0, len1 = 0, max1 = 0;
        vector<int> val(n, 0);
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                if(open){
                    open--;
                    len1 += 2;
                    max1 = max(max1, len1);
                }
                else{
                    len1 = 0;
                    val[i] = 1;
                }
            }
        }
        int close = 0, len2 = 0, max2 = 0;
        for(int i=n-1; i>=0; i--){
            if(val[i]){
                len2 = 0;
            }
            if(s[i] == ')') close++;
            else if(s[i] == '('){
                if(close){
                    close--;
                    len2 += 2;
                    max2 = max(max2, len2);
                }
                else len2 = 0;
            }
        }
        return min(max1, max2);
    }
};