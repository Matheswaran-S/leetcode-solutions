class Solution {
public:
    bool check(int mid, vector<int> &nums, int m, int k){
        int cnt = 0;
        for(int i=0; i<nums.size(); ){
            bool got = true;
            int j = i;
            while(j < nums.size() && j < i+k){
                if(nums[j] > mid){
                    got = false;
                }
                j++;
                if(!got) break;
            }
            if(got && j == i+k) cnt++;
            i = j;
        }
        if(cnt >= m) return true;
        return false;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 1LL*m*k) return -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid,nums,m,k)) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};