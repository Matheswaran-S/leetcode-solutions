class Solution {
private:
    int rev(int n){
        int num = 0;
        while(n > 0){
            num *= 10;
            num += n%10;
            n = n/10;
        }
        return num;
    }
public:
    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};