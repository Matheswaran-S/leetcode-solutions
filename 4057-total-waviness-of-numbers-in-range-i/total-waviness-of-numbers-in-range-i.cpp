class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for(int i=num1; i<=num2; i++){
            string s = to_string(i);
            int n = s.size();
            for(int i=1; i<n-1; i++){
                if(s[i-1] < s[i] && s[i+1] < s[i] || s[i-1] > s[i] && s[i+1] > s[i]) cnt++;
            }
        }
        return cnt;
    }
};