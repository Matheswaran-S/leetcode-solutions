class Solution {
private:
    void rev(string &s, int l, int r){
        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
public:
    string reverseWords(string s) {
        int n = s.size();
        int j = 0, f = 0;
        while(j < n && s[j] != ' '){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') f++;
            j++;
        }
        int l = j+1, r = j+1, cnt = 0;
        while(r < n){
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') cnt++;
            if(s[r] == ' '){
                if(cnt == f) rev(s, l, r-1);
                cnt = 0;
                l = r+1;
            }
            r++;
        }
        if(cnt == f) rev(s, l, r-1);
        return s;
    }
};