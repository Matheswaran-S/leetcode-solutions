class Solution {
public:
    long long sumAndMultiply(int n) {
        long long mul = 1, sum = 0, val = 0;
        while(n){
            if(n%10 != 0){
                val = (n%10)*mul + val;
                mul *= 10;
                sum += n%10;
            }
            n /= 10;
        }
        return sum*val;
    }
};