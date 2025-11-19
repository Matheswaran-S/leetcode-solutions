class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int bits = 0;
        for(auto i : nums){
            if(i%original == 0){
                int q = i/original;
                if((q&(q-1)) == 0) bits |= q;
            }
        }
        bits++;
        return ((bits & -bits) * original);
    }
};