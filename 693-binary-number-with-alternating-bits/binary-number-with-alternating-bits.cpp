class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=1, cur=0;
        if(n&1) prev = 0;
        while(n){
            cur = n&1;
            n = n>>1;
            if(cur == prev) return false;
            prev = cur;
        }
        return true;
    }
};