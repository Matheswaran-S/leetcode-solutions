class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1, t2 = 1;
        if(n<=1) return n;
        for(int i=3; i<=n; i++){
            t0 = t0+t1+t2;
            swap(t0,t2);
            swap(t2,t1);
        }
        return t1;
    }
};