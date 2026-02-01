class Solution {
private:
    int mn(vector<int> &nums, int idx, int n){
        int ind = -1, mini = INT_MAX;
        for(int i=1; i<n; i++){
            if(i != idx && nums[i] < mini){
                mini = nums[i];
                ind = i;
            }
        }
        return ind;
    }
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size(), f = nums[0];
        int s1 = mn(nums, -1, n);
        int s2 = mn(nums, s1, n);
        return f+nums[s1]+nums[s2];
    }
};