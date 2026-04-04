class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();
        int col = n/rows;
        //cout<<col<<endl;
        int i = 0;
        string temp, ans;
        while(i < col){
            int j = i;
            while(j < n){
                temp += s[j];
                j += (col+1);
            }
            i++;
        }
        int m = temp.size(), j = m-1;
        for(;j>=0; j--){
            if(temp[j] != ' ') break;
        }
        for(int i=0; i<=j; i++){
            ans += temp[i];
        }
        return ans;
    }
};