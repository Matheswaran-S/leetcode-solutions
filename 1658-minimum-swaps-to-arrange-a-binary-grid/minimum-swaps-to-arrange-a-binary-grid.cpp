class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rem(n);
        for(int i=0; i<n; i++){
            int z = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j] == 0) z++;
                else break;
            }
            rem[i] = z;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            int need = n-i-1, j = i;
            while(j<n && rem[j]<need) j++;
            if(j == n) return -1;
            cnt += j-i;
            while(j > i) swap(rem[j], rem[--j]);
        }
        return cnt;
    }
};