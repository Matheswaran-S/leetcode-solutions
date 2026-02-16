class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n; i++) mpp[nums[i]]++;
        unordered_map<int,int> mp;
        for(auto &[k,v] : mpp){
            mp[v]++;
        }
        for(int i=0; i<n; i++){
            if(mp[mpp[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};