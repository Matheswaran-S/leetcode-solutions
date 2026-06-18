class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = hour*5 + (2.5 / 30)*minutes;
        double ans = abs(hr - minutes)*6;
        return min(ans, 360-ans);
    }
};