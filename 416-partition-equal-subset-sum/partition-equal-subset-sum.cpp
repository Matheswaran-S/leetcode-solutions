class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        int n = nums.size();
        int tar = sum/2;
        vector<bool> prev(tar+1), cur(tar+1);
        for(int i=0; i<=tar; i++){
            if(i == 0 || i == nums[0]) prev[i] = true;
            else prev[i] = false;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=tar; j++){
                bool nt = prev[j];
                bool t = false;
                if(j-nums[i] >= 0) t = prev[j-nums[i]];
                cur[j] = nt|t;
            }
            prev = cur;
        }
        return prev[tar];
    }
};