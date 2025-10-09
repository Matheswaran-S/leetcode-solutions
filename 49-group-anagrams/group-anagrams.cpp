class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(),ind = 0;
        vector<vector<string>> ans(n);
        map<string,int> mpp;
        for(int i=0; i<n; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mpp[temp] == 0){
                ind++;
                mpp[temp] = ind;
            }
            ans[mpp[temp] - 1].push_back(strs[i]);
        }
        for(int i=n-1; i>=0; i--){
            if(ans[i].size() == 0) ans.pop_back();
        }
        return ans;
    }
};