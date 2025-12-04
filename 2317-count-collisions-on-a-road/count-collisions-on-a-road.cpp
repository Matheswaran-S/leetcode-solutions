class Solution {
public:
    int countCollisions(string s) {
        int cnt = 0, r = 0,prer = 0, n = s.size();
        while(r < n){
            if(s[r] == 'R'){
                if(r+1 < n){
                    if(s[r+1] == 'S'){
                        cnt += prer + 1;
                        s[r+1] = 'S';
                        prer = 0;
                    }
                    else if(s[r+1] == 'L'){
                        cnt += prer + 2;
                        s[r+1] = 'S';
                        prer = 0;
                    }
                    else{
                        prer++;
                    }
                }
            }
            else if(s[r] == 'L'){
                if(r-1 >= 0){
                    if(s[r-1] == 'R'){
                        cnt += 2;
                        s[r] = 'S';
                    }
                    else if(s[r-1] == 'S'){
                        cnt++;
                        s[r] = 'S';
                    }
                }
            }
            r++;
        }
        return cnt;
    }
};