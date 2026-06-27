#define ll long long
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        unordered_map<ll,int> vis, ans;
        for(int i=0; i<n; i++){
            ans[nums[i]] = 1;
            vis[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(nums[i] == 1) mx = max(mx, vis[nums[i]]%2 == 0? vis[nums[i]]-1 : vis[nums[i]]);
            else if(vis[nums[i]] > 1){
                ll num = 1ll*nums[i]*nums[i];
                int cnt = 1;
                vis[nums[i]] = 0;
                while(ans[num]){
                    if(vis[num] == 0){
                        cnt  = cnt + 1 + ans[num];
                        break;
                    }
                    else{
                        cnt = cnt + 2;
                        if(vis[num] > 1){
                            vis[num] = 0;
                            num = num*num;
                        }
                        else break;
                    }
                }
                ans[nums[i]] = cnt;
                mx = max(mx, cnt);
            }
            else if(vis[nums[i]] == 1) vis[nums[i]] = 0;
        }
        return mx;
    }
};