class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int f = nums[0], cnt = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(f != nums[i]){
                f = nums[i];
                cnt++;
            }
            sum += cnt;
        }
        return sum;
    }
};