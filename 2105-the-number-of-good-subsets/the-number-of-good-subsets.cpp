class Solution {
public:
    int mod = 1e9+7;
    int bexp(long long b, int e){
        int res = 1;
        b = b%mod;
        while(e){
            if(e%2 != 0){
                res = (res * (b%mod))%mod;
                e--;
            }
            b = (b*b)%mod;
            e = e/2;
        }
        return res;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        vector<int> prbit(31,0);
        for(int i=2; i<=30; i++){
            int bval = 0, n = i;
            for(int j=0; j<10; j++){
                if(primes[j] > n || n == 1) break;
                if(n%primes[j] == 0){
                    n /= primes[j];
                    bval |= (1<<j); 
                }
            }
            if(n == 1) prbit[i] = bval;
            else prbit[i] = 0;
        } 
        int n = nums.size(), o = count(nums.begin(), nums.end(), 1);
        int ocnt = bexp(2,o), pcnt = 0;
        vector<int> dp(2048, 0), cnt(31, 0);
        for(int i=0; i<n; i++) if(prbit[nums[i]]) cnt[nums[i]]++;
        for(int i=2; i<=30; i++){
            dp[prbit[i]] += cnt[i];
            for(int j=0; j<2048; j++){
                if((prbit[i]&j) == 0){
                    dp[prbit[i]|j] = (dp[prbit[i]|j]%mod + (1LL*cnt[i]%mod * dp[j]%mod)%mod)%mod;
                }
            }
        }
        for(int i=0; i<2048; i++) pcnt = (pcnt + dp[i]%mod)%mod;
        return ((1LL*pcnt%mod) * ocnt%mod)%mod;
    }
};