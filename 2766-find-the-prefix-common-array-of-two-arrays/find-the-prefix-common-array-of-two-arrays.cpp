class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> hash(n+1, 0);
        vector<int> ans(n,0);
        hash[A[0]] = 1;
        hash[B[0]] = 1;
        if(A[0] == B[0]) ans[0] = 1;
        for(int i=1; i<n; i++){
            ans[i] += ans[i-1];
            if(hash[A[i]]) ans[i]++;
            hash[A[i]] = 1;
            if(hash[B[i]]) ans[i]++;
            hash[B[i]] = 1;
        }
        return ans;
    }
};