class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0, rem, mini = INT_MAX,min1 = INT_MAX, min2 = INT_MAX, n = nums.size();
        for(int i=0; i<n; i++) sum += nums[i];
        rem = sum%3;
        if(rem == 0) return sum;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(rem == 1){
                if(nums[i]%3 == 1) mini = min(mini, nums[i]);
                else if(nums[i]%3 == 2){
                    if(min1 != INT_MAX) min2 = min(min2, nums[i]);
                    min1 = min(min1, nums[i]);
                }
            }
            else{
                if(nums[i]%3 == 2) mini = min(mini, nums[i]);
                else if(nums[i]%3 == 1){
                    if(min1 != INT_MAX) min2 = min(min2, nums[i]);
                    min1 = min(min1, nums[i]);
                }
            }
        }
        if(min1 == INT_MAX || min2 == INT_MAX){
            if(mini != INT_MAX) return sum - mini;
            else return sum;
        }
        else{
            if(mini != INT_MAX) return max(sum - mini, sum - min1 - min2);
            else return sum - min1 - min2;
        }
    }
};