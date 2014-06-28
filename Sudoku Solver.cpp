class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=0;k<9;k++){
                        board[i][j]=k+'1';
                        if ( isvalid(board,i,j) && solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool isvalid(vector<vector<char> > &board, int row, int col){
        int b_r = row/3;
        int b_c = col/3;     // get the block number
        for(int i=0;i<9;i++){
            if(board[i][col]==board[row][col] && i!=row) return false;
            if(board[row][i]==board[row][col] && i!=col) return false;
            int r=b_r*3+i/3;
            int c=b_c*3+i%3;
            if(board[r][c]==board[row][col] && !(r==row && c==col))  return false;
        }
        return true;
    }
};