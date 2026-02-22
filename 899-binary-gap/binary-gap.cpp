class Solution {
public:
    int binaryGap(int n) {
        int prev = -1, ans = 0, i=0;
        while(n){
            i++;
            if(n%2){
                if(prev == -1) prev = i;
                else{
                    ans = max(ans, i-prev);
                    prev = i;
                } 
            }
            n = n/2;
        }
        return ans;
    }
};