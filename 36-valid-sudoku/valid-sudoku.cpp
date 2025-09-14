class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            unordered_map<char,int> row;
            for(int j=0; j<9; j++){
                cout<<board[i][j]<<' '<<endl;
                if(row[board[i][j]] == 1) return false;
                else if(board[i][j] != '.') { row[board[i][j]] = 1; cout<<row[board[i][j]]<<' '<<endl;}
            }
            unordered_map<char,int> col;
            for(int j=0; j<9; j++){
                cout<<board[j][i]<<' '<<endl;
                if(col[board[j][i]] == 1) return false;
                else if(board[j][i] != '.') col[board[j][i]] = 1;
            }
            unordered_map<char,int> grid;
            for(int r = (i%3)*3; r< (i%3)*3 + 3; r++){
                for(int d = (i/3)*3; d<(i/3)*3 + 3; d++){
                    cout<<board[r][d]<<' '<<endl;
                    if(grid[board[r][d]] == 1) return false;
                    else if(board[r][d] != '.') grid[board[r][d]] = 1;
                }
            }
        }
        return true;
    }
};