class Solution {
public:
    bool validDigit(int n, int x) {
        if(n == x) return false;
        bool ans = false;
        while(n){
            if((n/10) == 0){
                if(n == x){
                    ans = false;
                    break;
                }
            }
            if((n%10) == x) ans = true;
            n = n/10;
        }
        return ans;
    }
};