class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        /*00 10 
        00 11
        00 12
        01 10
        01 11
        01 12
        02 10
        02 11
        02 12

        00 01 02 10 11 12

        00 01 10 02 12 */
        long long ans = 0;
        int m = queries.size(),r=0,c=0;
        map<pair<int,int>,bool> vis;
        for(int i=m-1; i>=0; i--){
            int ty = queries[i][0];
            int coo = queries[i][1];
            int val = queries[i][2];
            if(!vis[{ty,coo}]){
                vis[{ty,coo}] = true;
                if(ty == 0){
                    ans += val*(n-c);
                    r++;
                }
                else{
                    ans += val*(n-r);
                    c++;
                }
            }
        } 
        return ans;
    }
};