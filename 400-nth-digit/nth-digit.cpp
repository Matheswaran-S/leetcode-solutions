#define ll long long 
class Solution {
public:
    int findNthDigit(int n) {
        ll prev = 9, dig = 1, mul = 9, pidx = 9;
        if(n <= 9) return n;
        while((mul*10)*(dig+1)+pidx <= n){
            dig++;
            mul *= 10;
            pidx += mul*dig;
            prev  = prev*10 + 9;
        }
        dig++;
        ll diff = n-pidx, num = prev;
        num += diff/dig;
        if(diff%dig != 0){
            num += 1;
        }
        int mod = diff%dig;
        if(mod == 0) return num%10;
        mod = dig - mod;
        while(mod--){
            num = num/10;
        }
        return num%10;
    }
};