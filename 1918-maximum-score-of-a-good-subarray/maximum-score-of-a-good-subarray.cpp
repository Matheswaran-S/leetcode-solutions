class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k, j=k, n = nums.size(), mini = nums[k], ans = nums[k];
        while(i >=0 && j < n){
            int l = 0, r = 0;
            if(i>0) l = min(mini, nums[i-1])*(j-(i-1)+1);
            if(j<n-1) r = min(mini, nums[j+1])*(j+1-i+1);
            if(l==0 && r==0) break;
            if(l >= r){
                mini = min(mini, nums[i-1]);
                ans = max(ans, mini*(j-i+2));
                i--;
            }
            else{
                mini = min(mini, nums[j+1]);
                ans = max(ans, mini*(j-i+2));
                j++;
            }
        }
        return ans;
    }
};