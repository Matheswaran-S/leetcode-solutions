class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        set<vector<string>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                string top = words[i];
                string bottom = words[j];
                for(int k=0; k<n; k++){
                    if(k == i || k == j) continue;
                    string left = words[k];
                    if(top[0] != left[0] || bottom[0] != left[3]) continue;
                    for(int l=0; l<n; l++){
                        if(l == i || l == j || l == k) continue;
                        string right = words[l];
                        if(top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3]) ans.insert({top,left,right,bottom});
                    }
                }
            }
        }
        vector<vector<string>> res;
        for(auto i : ans) res.push_back(i);
        return res;
    }
};