#define ll long long

class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9) return k;

        ll pref = 9, nine = 9, dig = 2, act = 9;

        while (pref + dig * nine * 10 < k) {
            nine *= 10;
            pref += dig * nine;
            dig++;
            act = act*10 + 9;
        }

        bool rev;

        if (((k - pref - 1) / (dig * 10)) & 1) {
            if (dig == 2)
                rev = false;
            else
                rev = true;
        }
        else {
            if (dig == 2)
                rev = true;
            else
                rev = false;
        }

        ll rem = k - pref-1;
        ll num = act + (rem/dig) + 1;
        if(rev) num = (num/10)*10 + (9 - num%10);
        string s = to_string(num);
        return s[rem%dig]-'0';
    }
};