class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, rem = numBottles;
        while(rem >= numExchange){
            int exc = (rem/numExchange);
            ans += exc;
            rem -= (numExchange*exc);
            rem += exc;
        }
        return ans;
    }
};