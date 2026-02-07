class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), a = count(s.begin(), s.end(), 'a'), b = 0, mn = INT_MAX;        
        for(int i=0; i<n; i++){
            if(s[i] == 'a') a--;
            mn = min(mn, a+b);
            if(s[i] == 'b') b++;
        }      
        return mn;
    }
};