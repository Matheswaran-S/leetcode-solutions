class Solution {
public:
    int digitFrequencyScore(int n) {
        int s = 0;
        while(n){
            s += n%10;
            n = n/10;
        }
        return s;
    }
};