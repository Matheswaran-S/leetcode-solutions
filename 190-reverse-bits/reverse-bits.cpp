class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i=0; i<=31; i++){
            ans += ((n>>i)&1)*(1<<(31-i));
        }
        return ans;
    }
};