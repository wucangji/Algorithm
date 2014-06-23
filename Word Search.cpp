class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()  || board[0].empty()) return false;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(help(board,i,j,word,0)) return true;
            }
        }
        return false;
    }
    
bool help(vector<vector<char> > &board, int row, int col, 
		string &word, int begin)
	{
	    
		if (begin == word.size()) return true;
		if (row<0 || row>=board.size() || col<0 || col>=board[0].size() 
			|| board[row][col] != word[begin]) return false;
		
		char t = board[row][col];   // t cannot be put into the if above
		board[row][col] = '*';
		if (help(board, row+1, col, word, begin+1)
			|| help(board, row, col+1, word, begin+1)
			|| help(board, row-1, col, word, begin+1)
			|| help(board, row, col-1, word, begin+1))
			return true;
		board[row][col] = t;
		return false;
	}

};

