class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int  i : nums){
            sum += i;
        }
        int s = 0,cnt = 0;
        for(int i=0; i<n-1; i++){
            sum -= nums[i];
            s += nums[i];
            if(abs(s - sum)%2 == 0) cnt++;
        }
        return cnt;
    }
};