class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            pre[i] = __gcd(pre[i-1], nums[i]);
            suf[n-i-1] = __gcd(suf[n-i], nums[n-i-1]);
        }
        int op = 0;
        for(int i=0; i<n-1; i++){
            if(pre[i] == suf[i+1]) op++;
        }
        ans = max(ans, op);
        vector<int> pr(n-1), sf(n-1);
        for(int i=0; i<n; i++){
            pr[0] = (i == 0)? nums[1] : nums[0];
            sf[n-2] = (i == n-1)? nums[n-2] : nums[n-1];
            int i1 = 0, i2 = n-2, op = 0; 
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if((i == 0 && j == 1) || (i != 0 && j == 0)) continue;
                pr[i1 + 1] = __gcd(pr[i1], nums[j]);
                i1++;
            }
            for(int j=n-1; j>=0; j--){
                if(i == j) continue;
                if((i == n-1 && j == n-2) || (i != n-1 && j == n-1)) continue;
                sf[i2 - 1] = __gcd(sf[i2], nums[j]);
                i2--;
            }
            for(int j=0; j<n-2; j++){
                if(pr[j] == sf[j+1]) op++;
            }
            ans = max(ans, op);
        }
        return ans;
    }
};