class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*0-0 2
        0-1 4
        1-0 3
        1-1 5*/

        int m=board.size(), n=board[0].size();
        int dx[] = {-1,0,1,0,-1,-1,1,1};
        int dy[] = {0,1,0,-1,-1,1,-1,1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                bool z = 1-board[i][j];
                int odd = 0, even = 0;
                for(int k=0; k<8; k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x < m && x>=0 && y>=0 && y<n){
                        odd += (board[x][y]&1);
                        even += (!(board[x][y]%2));
                    }
                }
                if(z){
                    if(odd == 3) board[i][j] = 4;
                    else board[i][j] = 2;
                }
                else{
                    if(odd == 2 || odd == 3) board[i][j] = 5;
                    else board[i][j] = 3;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int v = board[i][j];
                if(v<=3) board[i][j] = 0;
                else board[i][j] = 1;
            }
        }
    }
};