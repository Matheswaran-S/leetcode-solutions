class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size(), ans = 0;
        for(int i=0; i<n; i++){
            int score = 0;
            for(int j=i; j<i+n-1; j++){
                score += (s[j%n] == s[(j+1)%n])? 1 : 0;
            }
            ans += (score == k);
        }   
        return ans;
    }
};