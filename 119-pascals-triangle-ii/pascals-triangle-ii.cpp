class Solution {
public:
    long long fact(int n){
        long long f = 1;
        for(long long i = 2; i<=n; i++){
            f *= i;
        }
        return f;
    }
public:
    vector<int> getRow(int r) {
        vector<int> res(r+1),prev(r+1);
        for(int i=0; i<=r; i++){
            for(int j=0; j<=i; j++){
                if(j == 0 || j == i) res[j] = 1;
                else res[j] = prev[j]+prev[j-1];
            }
            prev = res;
        }
        return res;
    }
};