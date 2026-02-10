class Solution {
private:
    void sieve(int n, vector<int> &v){
        for(int i=2; i<n; i++) v[i] = 1;
        for(int i=2; i*i<n; i++){
            for(int j=i*i; j<n; j += i){
                v[j] = 0;
            }
        }
    }
public:
    int countPrimes(int n) {
        vector<int> v(n,0);
        sieve(n,v);
        int ans = 0;
        for(int i=2; i<n; i++) if(v[i]) ans++;
        return ans;
    }
};