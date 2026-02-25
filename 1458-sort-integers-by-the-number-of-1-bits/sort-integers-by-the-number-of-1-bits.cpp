class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> mpp;
        for(int i=0; i<n; i++){
            mpp.push_back({__builtin_popcount(arr[i]),arr[i]});
        }
        sort(mpp.begin(), mpp.end());
        vector<int> ans;
        for(auto &[k,v] : mpp) ans.push_back(v);
        return ans; 
    }
};