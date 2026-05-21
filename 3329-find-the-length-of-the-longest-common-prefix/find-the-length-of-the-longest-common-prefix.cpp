class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), ans = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int x = arr1[i], d = 100000000, c = 9;
            while(x){
                if(x >= d){
                    mpp[x] = c;
                    x /= 10;
                }
                d /= 10;
                c--;
            }
        } 
        for(int i=0; i<m; i++){
            int y = arr2[i];
            while(y){
                if(mpp[y]) ans = max(ans, mpp[y]);
                y = y/10;
            }
        }
        return ans;
    }
};