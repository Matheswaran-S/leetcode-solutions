class Solution {
private:
    int rec(int k){
        if(k == 1) return 0;
        if((k&(k-1)) == 0) return 1;
        int i;
        for(i=20; i>=0; i--) if(k&(1<<i)) break;
        int diff = k-(1<<i);
        return 1 - rec(k-(2*diff));
    }
public:
    char findKthBit(int n, int k) {
        return rec(k)+'0';
    }
};