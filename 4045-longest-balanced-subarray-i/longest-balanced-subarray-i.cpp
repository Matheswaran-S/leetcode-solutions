class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for(int i=0; i<n; i++){
            int od = 0, ev = 0;
            unordered_map<int,int> mpp;
            for(int j=i; j<n; j++){
                if(!mpp[nums[j]]){
                    mpp[nums[j]] = 1;
                    if(nums[j] & 1) od++; 
                    else ev++;
                }
                if(od == ev) mx = max(mx, j-i+1);
            }
        }
        return mx;
    }
};