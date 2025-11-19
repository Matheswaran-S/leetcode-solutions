class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int r = 0, n = bits.size();
        while(r < n-1){
            if(bits[r] == 1) r++;
            r++;
        }
        if(r == n-1) return true;
        return false;
    }
};