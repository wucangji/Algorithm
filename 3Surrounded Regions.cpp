// ============run out of time ============== 下面的


class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty() || board[0].empty()) return;
        
        for(int i=0;i<board.size();i++){
            backtrack(board,i,0);
            backtrack(board,i,board[0].size()-1);      // 左右两列
        }
        
        for(int j=1;j<board[0].size()-1;j++){
            backtrack(board,0,j);
            backtrack(board,board.size()-1,j);
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(board[i][j] == '*')    board[i][j]='0';    //  * mean not surround
               else board[i][j]='X';
            }
        }
    }
private:   
    void backtrack(vector<vector<char> > &board, int row, int col){
        if(!isLegal(board,row,col)) return;
        board[row][col] = '*';
        backtrack(board,row+1,col);
        backtrack(board,row,col+1);
        backtrack(board,row-1,col);
        backtrack(board,row,col-1);
    }
    
    bool isLegal(vector<vector<char> > &board, int i, int j)  
    {  
        return   
        !(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != 'O');  
    }  
};