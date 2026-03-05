class Solution {
public:
    int largestPrime(int n) {
        vector<int> v(n+1,1);
        for(int i=2; i*i<=n; i++){
            if(v[i]){
                for(int j=i*i; j<=n; j += i) v[j] = 0;
            }
        }
        vector<int> mpp(n+1,0);
        long long ans = 0, psum = 0;
        for(int i=2; i<=n; i++){
            if(v[i]){
                psum += i;
                if(psum <= n) mpp[psum] = 1;
                if(mpp[i]) ans = max(ans,1ll*i);
            }
        }
        return ans;
    }
};