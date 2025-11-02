class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=INT_MAX, maxi = INT_MIN, n = nums.size();
        unordered_map<int,short> mpp;
        for(int i=0; i<n; i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            mpp[nums[i]] = 1;
        }
        vector<int> res;
        for(int i=mini+1; i<maxi; i++){
            if(!mpp[i]) res.push_back(i);
        }
        return res;
    }
};