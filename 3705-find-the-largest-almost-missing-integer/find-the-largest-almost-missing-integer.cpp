class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(k == n) return *max_element(nums.begin(),nums.end());
        vector<int> freq(51, 0);
        for(int i=0; i<n; i++) freq[nums[i]]++;
        if(k == 1){
            for(int i=50; i>=0; i--){
                if(freq[i] == 1) return i;
            }
        }
        int mx = -1;
        if(freq[nums[0]] == 1) mx = max(mx, nums[0]);
        if(freq[nums[n-1]] == 1) mx = max(mx, nums[n-1]);
        return mx;
    }
};