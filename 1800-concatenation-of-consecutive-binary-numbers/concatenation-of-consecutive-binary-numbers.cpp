#define ll long long
#define mod 1000000007
class Solution {
public:
    ll cnt(ll n){
        ll c=0;
        while(n){
            c++;
            n = n/2;
        }
        return c;
    }
    ll exp(ll base, ll p){
        ll res = 1;
        while(p){
            if(p&1) res = (res*(base%mod))%mod;
            base = ((base%mod)*(base%mod))%mod;
            p = p>>1;
        }
        return res;
    }
    int concatenatedBinary(int n) {
        ll ans = 0, sft = 0;
        for(ll i=n; i>=1; i--){
            ans = (ans + ((i%mod)*exp(2LL,sft))%mod)%mod;
            sft += cnt(i);
            //cout<<ans<<' '<<sft<<endl;
        }  
        return ans;
    }
};