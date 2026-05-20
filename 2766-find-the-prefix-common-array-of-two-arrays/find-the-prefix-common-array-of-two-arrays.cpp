class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> hash(n+1, 0);
        vector<int> ans;
        for(int i=0; i<n; i++){
            hash[A[i]] = 1;
            int cnt = 0;
            for(int j=0; j<=i; j++){
                if(hash[B[j]]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};