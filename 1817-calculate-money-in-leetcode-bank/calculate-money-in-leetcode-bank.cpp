class Solution {
public:
    int totalMoney(int n) {
        int div = n/7, rem = n%7;
        if(div == 0) return rem*(rem+1)/2;
        return (div*28 + ((div-1)*(div))/2 * 7)+(rem*(rem+1)/2 + div*rem);
    }
};