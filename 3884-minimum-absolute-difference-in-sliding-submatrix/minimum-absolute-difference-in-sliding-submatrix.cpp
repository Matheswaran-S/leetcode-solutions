class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
        for(int i=0; i<m-k+1; i++){
            for(int j=0; j<n-k+1; j++){
                set<int> st;
                for(int r=i; r<i+k; r++){
                    for(int c=j; c<j+k; c++){
                        st.insert(grid[r][c]);
                    }
                }
                int prev = INT_MAX, cur, mini = INT_MAX;
                for(auto &e : st){
                    cur = e;
                    if(prev != INT_MAX) mini = min(mini, abs(cur-prev));
                    prev = cur;
                }
                ans[i][j] = (mini != INT_MAX)? mini : 0;
            }
        }
        return ans;
    }
};