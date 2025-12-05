class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0, ans = 0;
        for(int i = n-1; i>=0; i--){
            if(i+1<n && nums[i] != nums[i+1]){
                cnt = (n-i-1);
            }
            if(cnt >= k) ans++;
        }
        return ans;
    }
};