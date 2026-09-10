class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int> mpp;
        for(int i=0; i<n; i++) mpp[nums[i]] = i+1;
        int ans = 1;
        vector<bool> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                long long num = nums[i];
                int cnt = 1;
                while(mpp[1LL*num*num]){
                    num = 1LL*num*num;
                    vis[mpp[num]] = 1;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        if(ans > 1) return ans;
        return -1;
    }
};