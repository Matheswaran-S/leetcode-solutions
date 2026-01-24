class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int xones = __builtin_popcount(num2);
        int num1s = __builtin_popcount(num1);
        int x = num1;
        if(xones == num1s) return x;
        else if(xones > num1s){
            int rem = xones-num1s,i=0;
            while(rem && i < 32){
                if(!(num1&(1<<i))){
                    x |= (1<<i);
                    rem--;
                }
                i++;
            }
            return x;
        }
        else{
            int i=31, x=0;
            while(xones){
                if(num1&(1<<i)){
                    xones--;
                    x |= (1<<i);
                }
                i--;
            }
            return x;
        }
    }
};