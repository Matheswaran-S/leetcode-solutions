class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> mpp(101,0);
        for(auto &n : nums) mpp[n] = 1;
        int c = k;
        while(true){
            if(c > 100 || !mpp[c]) return c;
            c += k;
        }
    }
};