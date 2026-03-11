class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0;
        bool seen = false;
        for(int i=31; i>=0; i--){
            if(n&(1<<i)) seen = true;
            else{
                if(seen) ans |= (1<<i);
            }
        }
        return ans;
    }
};