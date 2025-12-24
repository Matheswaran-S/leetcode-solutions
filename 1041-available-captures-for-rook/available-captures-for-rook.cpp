class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = 8, row=-1, col=-1, cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'R'){
                    row = i, col = j;
                    break;
                }
            }
            if(row != -1) break;
        }
        for(int i = row-1; i>=0; i--){
            if(board[i][col] == 'p'){
                cnt++;
                break;
            }
            else if(board[i][col] == 'B') break;
        }
        for(int i = row+1; i<n; i++){
            if(board[i][col] == 'p'){
                cnt++;
                break;
            }
            else if(board[i][col] == 'B') break;
        }
        for(int i = col-1; i>=0; i--){
            if(board[row][i] == 'p'){
                cnt++;
                break;
            }
            else if(board[row][i] == 'B') break;
        }
        for(int i = col+1; i<n; i++){
            if(board[row][i] == 'p'){
                cnt++;
                break;
            }
            else if(board[row][i] == 'B') break;
        }
        return cnt;
    }
};