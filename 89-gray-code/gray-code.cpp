class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        ans[0] = 0;
        for(int i=1; i<=n; i++){
            int off = (1<<i-1);
            for(int j=off-1; j>=0; j--){
                ans[off+(off-1-j)] = (ans[j] | off); 
            }
        }
        return ans;
    }
};