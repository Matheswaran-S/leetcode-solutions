class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size(), ans = 0;
        for(int i=0; i<n; i++) mpp[nums[i]]++;
        for(auto &[k,i] : mpp){
            if(i == 1) return -1;
            else ans += (i+2)/3;
        }
        return ans;
    }
};