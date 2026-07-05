#define mod 1000000007
class Solution {
public:
    void f(vector<int> &sieve){
        int n = sieve.size();
        for(int i=2; i<n; i++) sieve[i] = i;
        for(int i=2; i*i<=n; i++){
            if(sieve[i] == i){
                for(int j = i*i; j<n; j += i){
                    if(sieve[j] == j) sieve[j] = i;
                }
            }
        }
    }
    int divisibleGame(vector<int>& nums) {
        int mxi = *max_element(nums.begin(), nums.end());
        vector<int> sieve(mxi+1, 1);
        f(sieve);
        unordered_set<int> primes;
        primes.insert(2);
        int n = nums.size();
        for(int i=0; i<n; i++){
            int v = nums[i];
            while(v != 1){
                primes.insert(sieve[v]);
                v /= sieve[v];
            }
        }
        long long ans1 = LLONG_MIN, mul = LLONG_MAX;
        for(auto &v : primes){
            long long pr = v, sum = 0, mx = LLONG_MIN;
            for(int i=0; i<n; i++){
                if(nums[i]%pr == 0) sum += (nums[i]);
                else sum -= nums[i];
                mx = max(mx, sum);
                sum = max(0LL, sum);
            }
            if(ans1 == mx){
                mul = min(mul, pr);
            }
            else if(ans1 < mx){
                ans1 = mx;
                mul = pr;
            }
        }
        if(ans1*mul >= 0) return (ans1*mul)%mod;
        else return (ans1*mul + mod)%mod;
    }
};