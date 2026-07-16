class Solution {
public:
    int minNumberOfFrogs(string s) {
        int n = s.size(), c=0, r=0, o=0, a=0, k=0, cnt = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'c'){
                c++;
                cnt++;
            }
            else if(s[i] == 'r') r++;
            else if(s[i] == 'o') o++;
            else if(s[i] == 'a') a++;
            else if(s[i] == 'k'){
                k++;
                cnt--;
            }
            if(!(c>=r && r>=o && o>=a && a >= k)) return -1;
            ans = max(ans, cnt);
        }
        if(c == r && r == o && o == a && a == k && c+r+o+a+k == n) return ans;
        return -1;
    }
};