class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int l = 0, r = 0, n = nums.size();
        vector<int> arr;
        while(r < n){
            while(!dq.empty() && nums[dq.back()] <= nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(r-l+1 == k){
                arr.push_back(nums[dq.front()]);
                l++;
                if(dq.front() < l) dq.pop_front();
            }
            r++;
        }
        return arr;
    }
};