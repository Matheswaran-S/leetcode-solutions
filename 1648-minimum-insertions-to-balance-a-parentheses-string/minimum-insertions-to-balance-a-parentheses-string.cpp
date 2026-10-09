class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), c = 0, ans = 0;
        for(int i=0; i<n; i++){
            c += (s[i] == '(')? 2 : 0;
            if(s[i] == ')'){
                if(i+1 < n && s[i+1] == ')' && c >= 2){
                    c -= 2;
                    i++;
                }
                else if(i+1 < n && s[i+1] == ')' && c < 2){
                    ans++;
                    c = 0;
                    i++;
                }
                else if(c >= 2){
                    ans++;
                    c -= 2;
                }
                else{
                    ans += 2;
                    c = 0;
                }
            }
        }
        return ans+abs(c);
        //(()))) (()))) ()) ()) ())
        //1 + 1 + 1 + 1
    }
};