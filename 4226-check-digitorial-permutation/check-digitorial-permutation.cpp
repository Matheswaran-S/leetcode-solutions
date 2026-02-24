class Solution {
private:
    int fact(int n){
        int f = 1;
        for(int i=2; i<=n; i++) f *= i;
        return f;
    }
public:
    bool isDigitorialPermutation(int n) {
        vector<int> f(10,0);
        int fsum = 0, t = n;
        while(t){
            fsum += fact(t%10);
            f[t%10]++;
            t = t/10;
        }
        while(fsum){
            f[fsum%10]--;
            if(f[fsum%10] < 0) return false;
            fsum /= 10;            
        }
        for(int i=0; i<=9; i++){
            if(f[i] != 0) return false;
        }
        return true;

    }
};