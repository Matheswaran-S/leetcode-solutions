class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0, r = 0, e = 0, le = 0, cnt = 0;
        while(r < n && l <= r){
            cnt += nums[r];
            while(cnt >= goal && l<=r){
                cnt = cnt - nums[l];
                l++;
            }
            le += (r-l+1);
            r++;
        }
        l=0, r=0, cnt = 0;
        while(r < n && l <= r){
            cnt += nums[r];
            while(cnt > goal){
                cnt = cnt - nums[l];
                l++;
            }
            e += (r-l+1);
            r++;
        }
        return e-le;
    }
};