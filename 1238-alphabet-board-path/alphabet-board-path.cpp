class Solution {
private:
    string fun(char pre, char cur, vector<vector<int>> &coo){
        int x1 = coo[pre-'a'][0], y1 = coo[pre-'a'][1];
        int x2 = coo[cur-'a'][0], y2 = coo[cur-'a'][1];
        string res;
        while(x1 < x2){
            res += 'D';
            x1++;
        }
        while(x1 > x2){
            res += 'U';
            x1--;
        }
        while(y1 < y2){
            res += 'R';
            y1++;
        }
        while(y1 > y2){
            res += 'L';
            y1--;
        }
        return res;
    }
public:
    string alphabetBoardPath(string target) {
        //vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        int n = target.size();
        vector<vector<int>> coo(26, vector<int>(2));
        int x = 0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                coo[x] = {i,j};
                x++;
            }
        }
        coo[x] = {5, 0};
        char pre = 'a',cur;
        string ans;
        for(int i=0; i<n; i++){
            cur = target[i];
            if(pre == cur){
                ans += '!';
                pre = cur;
            }
            else{
                if(pre == 'z'){
                    ans += 'U';
                    pre = 'u';
                }
                bool fi = 0;
                if(cur == 'z'){
                    fi = 1;
                }
                ans += (fi? fun(pre,'u',coo)+'D' : fun(pre,cur,coo));
                ans += '!';
                pre = cur;
            }
        }
        return ans;
    }
};