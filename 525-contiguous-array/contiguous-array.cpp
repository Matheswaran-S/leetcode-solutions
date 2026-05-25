class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size(), cnt = 0, maxlen = 0;
        mpp[0] = -1;
        for(int i=0; i<n; i++){
            cnt += (nums[i] == 0 ? -1 : 1);
            if(mpp.find(cnt) != mpp.end()){
                maxlen = max(maxlen, i-mpp[cnt]);
            }
            else mpp[cnt] = i;
        }
        return maxlen;
    }
};