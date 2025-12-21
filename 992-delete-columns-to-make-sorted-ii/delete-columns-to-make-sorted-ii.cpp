class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), cnt = 0;
        vector<bool> v(n, false);
        for(int i=0; i<m; i++){
            bool ok = true;
            for(int j=0; j<n-1; j++){
                if(!v[j] && strs[j][i] > strs[j+1][i]){
                    cnt++;
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            for(int j=0; j<n-1; j++){
                v[j] = v[j] | (strs[j][i] < strs[j+1][i]);
            }
        }
        return cnt;
    }
};