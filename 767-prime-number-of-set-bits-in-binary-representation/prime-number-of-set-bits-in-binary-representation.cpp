class Solution {
private:
    void sieve(int n, vector<int> &p){
        p[1] = 0;
        for(int i=2; i*i<=n; i++){
            if(p[i]){
                for(int j=i*i; j<=n; j += i){
                    p[j] = 0;
                }
            }
        }
    }
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> p(33, 1);
        sieve(32, p);
        int cnt = 0;
        for(int i=left; i<=right; i++){
            if(p[__builtin_popcount(i)]) cnt++;
        }
        return cnt;
    }
};