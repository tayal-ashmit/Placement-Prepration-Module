class Solution {
public:
    bool valid(vector<vector<char>>& board, int row, int col, char k) {
        for(int i=0; i<9; i++) {
            if(board[i][col]==k && i!=row)
                return false;
        }

        for(int j=0; j<9; j++) {
            if(board[row][j]==k && j!=col)
                return false;
        }

        int r= 3*(row/3);
        int c= 3*(col/3);
        for(int i=r; i<r+3; i++) {
            for(int j=c; j<c+3; j++) {
                if(board[i][j]==k && i!=row && j!=col)
                    return false;
            }
        }
        
        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char c='1'; c<='9'; c++) {
                        if(valid(board, i, j, c)) {
                            board[i][j]=c;
                            if(solve(board))
                                return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};