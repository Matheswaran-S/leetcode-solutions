class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,bool> mpp;
        for(auto &n : nums) mpp[n] = 1;
        int c = k;
        while(true){
            if(!mpp[c]) return c;
            c += k;
        }
    }
};