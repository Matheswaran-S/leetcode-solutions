class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size(), ans = 10000;
        for(int i=0; i<n; i++){
            int sum = 0, num = nums[i];
            while(num){
                sum += num%10;
                num = num/10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};