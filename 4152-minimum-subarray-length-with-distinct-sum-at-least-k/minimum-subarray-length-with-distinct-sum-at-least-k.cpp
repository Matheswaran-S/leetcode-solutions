class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        int l=0, r=0;
        int mini = INT_MAX, sum = 0;
        while(r < n){
            mpp[nums[r]]++;
            if(mpp[nums[r]] == 1) sum += nums[r];
            while(sum >= k){
                mini = mini = min(mini, r-l+1);
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) sum -= nums[l];
                l++;
            }
            r++;
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};