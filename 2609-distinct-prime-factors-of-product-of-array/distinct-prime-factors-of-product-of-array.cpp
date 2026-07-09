class Solution {
public:
    void sieve(vector<int> &fac){
        for(int i=2; i<=1000; i++) fac[i] = i;
        for(int p=2; p*p <= 1000; p++){
            if(fac[p] == p){
                for(int j=p*p; j<=1000; j += p) fac[j] = p;
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> fac(1001);
        sieve(fac);
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num = nums[i];
            while(num != 1){
                st.insert(fac[num]);
                num /= fac[num];
            }
        }
        return st.size();
    }
};