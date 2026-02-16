class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxi = 0, n = nums.size();
        for(int i=0; i<n; i++) mpp[nums[i]] = 1;
        for(int i=0; i<n; i++){
            if(!mpp[nums[i]+1]){
                int cnt = 0;
                while(mpp[nums[i]--]){
                    cnt++;
                    mpp[nums[i]+1] = 0;
                }
                cout<<cnt<<' '<<maxi<<endl;
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};