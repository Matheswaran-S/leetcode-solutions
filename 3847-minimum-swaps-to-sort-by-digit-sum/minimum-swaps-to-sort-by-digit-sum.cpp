class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,int>> st;
        unordered_map<int,int> pre, ind;
        for(int i=0; i<n; i++){
            int num = nums[i], sum = 0;
            while(num){
                sum += num%10;
                num /= 10;
            }
            st.insert({sum,nums[i]});
            pre[nums[i]] = i;
            ind[i] = nums[i];
        }
        int c = 0, ans = 0;
        for(auto &it : st){
            int num = it.second;
            if(pre[num] != c){
                ans++;
                pre[ind[c]] = pre[num];
                ind[pre[num]] = ind[c];
                pre[num] = c;
                ind[c] = num;
            }
            c++;
        }
        return ans;
    }
};