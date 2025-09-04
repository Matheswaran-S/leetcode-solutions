class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(y-z) > abs(x-z)) return 1;
        else if(abs(y-z) < abs(x-z)) return 2;
        return 0; 
    }
};