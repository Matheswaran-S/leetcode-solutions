class Solution {
public:
    string sortVowels(string s) {
        vector<int> v(10,0);
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == 'A') v[0]++;
            else if(s[i] == 'E') v[1]++;
            else if(s[i] == 'I') v[2]++;
            else if(s[i] == 'O') v[3]++;
            else if(s[i] == 'U') v[4]++;
            else if(s[i] == 'a') v[5]++;
            else if(s[i] == 'e') v[6]++;
            else if(s[i] == 'i') v[7]++;
            else if(s[i] == 'o') v[8]++;
            else if(s[i] == 'u') v[9]++;
        }
        for(int i=0; i<n; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                if(v[0]){
                    s[i] = 'A';
                    v[0]--;
                }
                else if(v[1]){
                    s[i] = 'E';
                    v[1]--;
                }
                else if(v[2]){
                    s[i] = 'I';
                    v[2]--;
                }
                else if(v[3]){
                    s[i] = 'O';
                    v[3]--;
                }
                else if(v[4]){
                    s[i] = 'U';
                    v[4]--;
                }
                else if(v[5]){
                    s[i] = 'a';
                    v[5]--;
                }
                else if(v[6]){
                    s[i] = 'e';
                    v[6]--;
                }
                else if(v[7]){
                    s[i] = 'i';
                    v[7]--;
                }
                else if(v[8]){
                    s[i] = 'o';
                    v[8]--;
                }
                else if(v[9]){
                    s[i] = 'u';
                    v[9]--;
                }
            }
        }
        return s;
    }
};