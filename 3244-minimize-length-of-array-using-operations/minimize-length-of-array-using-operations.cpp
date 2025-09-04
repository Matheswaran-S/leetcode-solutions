class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 1 || nums[0] != nums[1]) return 1;
        int tar = nums[0],cnt = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == tar) cnt++;
            else if(nums[i] != tar && nums[i]%tar != 0) return 1;
        }
        return (cnt/2)+(cnt%2);
    }
};