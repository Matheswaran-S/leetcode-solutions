class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int mini = INT_MAX;
        for(int i=0; i<n; i++) mini = min(mini, nums[i]);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == mini) cnt++;
            else if(nums[i]%mini != 0) return 1;
        }
        return (cnt/2)+(cnt%2);
    }
};