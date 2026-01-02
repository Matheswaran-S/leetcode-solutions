class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size()/2;
        for(auto i : nums){
            mpp[i]++;
            if(mpp[i] == n) return i;
        }
        return n;
    }
};