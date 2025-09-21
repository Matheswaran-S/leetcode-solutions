class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n <= 2) return 0;
        sort(nums.begin(), nums.end());
        for(int i=2; i<n; i++){
            int l = 0, r = i-1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    ans += r-l;
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};