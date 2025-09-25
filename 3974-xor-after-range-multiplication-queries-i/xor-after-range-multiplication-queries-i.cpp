class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), n = nums.size();
        for(int i=0; i<q; i++){
            int idx = queries[i][0];
            while(idx <= queries[i][1]){
                nums[idx] = ((long long)nums[idx] * (long long)queries[i][3])% (1000000007);
                idx += queries[i][2];
            }
        }
        int x = nums[0];
        for(int i=1; i<n; i++){
            x ^= nums[i];
        }
        return x;
    }
};