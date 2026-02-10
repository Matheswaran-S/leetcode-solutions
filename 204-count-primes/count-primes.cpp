class Solution {
private:
    int sieve(int n, vector<int> &v, int ans){
        for(int i=2; i<n; i++) v[i] = 1;
        for(int i=2; i*i<n; i++){
            if(v[i]){
                for(int j=i*i; j<n; j += i){
                    if(v[j]) ans--;
                    v[j] = 0;
                }
            }
        }
        return ans;
    }
public:
    int countPrimes(int n) {
        vector<int> v(n,0);
        return max(0,sieve(n,v,n-2));
        /*int ans = 0;
        for(int i=2; i<n; i++) if(v[i]) ans++;
        return ans;*/
    }
};