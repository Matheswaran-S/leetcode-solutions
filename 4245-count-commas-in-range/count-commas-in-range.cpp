class Solution {
public:
    int countCommas(int n) {
        int t = n, cnt = 0;
        while(t){
            cnt++;
            t = t/10;
        }
        cnt = (cnt-1)/3;
        if(cnt) return n-1000+1;
        return 0;
    }
};