class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        stack<long long> st;
        unordered_map<int,int> mpp;
        long long ans = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() > nums[i]){
                mpp[st.top()]--;
                st.pop();
            }
            st.push(nums[i]);
            mpp[nums[i]]++;
            ans += (st.size() - mpp[nums[i]]);
        }
        return ans;
    }
};