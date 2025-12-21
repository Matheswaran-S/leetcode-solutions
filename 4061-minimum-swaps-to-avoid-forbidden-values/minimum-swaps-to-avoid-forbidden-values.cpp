class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size(),ans = 0;
        unordered_map<int, int> mpp;
        unordered_map<int,int> com;
        vector<int> vals;
        for(int i=0; i<n; i++){
            if(nums[i] == forbidden[i]){
                mpp[nums[i]]++;
                com[nums[i]]++;
            }
            else{
                mpp[nums[i]]++;
                mpp[forbidden[i]]++;
            }
        }
        int cnt = 0;
        for(auto &[k,v] : com){
            if(v > n - mpp[k]) return -1;
            vals.push_back(v);
        }
        sort(vals.rbegin(), vals.rend());
        for(auto v : vals){
            if(v <= cnt) cnt -= v;
            else{
                ans += (v - cnt);
                cnt = v - cnt;
            }
        }
        return ans;
    }
};