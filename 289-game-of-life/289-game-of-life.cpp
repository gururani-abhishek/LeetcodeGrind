class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //vector<vector<int>> newBoard(board.size());
        int newBoard[board.size()][board[0].size()];
        
        for(int i=0; i<board.size(); i++) {
            for(int  j =0; j<board[0].size(); j++) {
                if(board[i][j] == 1) {
                    int count = helperFun(board, i, j);
                    if(count < 2) newBoard[i][j] = 0;
                    else if(count > 3) newBoard[i][j] = 0;
                    else newBoard[i][j] = board[i][j];
                }else {
                    int count = helperFun(board, i, j);
                    if(count == 3) newBoard[i][j] = 1;
                    else newBoard[i][j] = board[i][j];
                }
            }
        }
        for(int i=0; i<board.size(); i++) {
            for(int j =0; j<board[0].size(); j++) {
                board[i][j] = newBoard[i][j];
            }
        }
    }
private: 
    int helperFun(vector<vector<int>>& board, int i, int j) {
            int cnt = 0;
            int R = board.size(), C = board[0].size();
        
            cnt += (i-1 >= 0) && board[i-1][j] ? 1 : 0;
            cnt += (i-1 >= 0 && j-1 >= 0) && board[i-1][j-1] ? 1 : 0;
            cnt += (i-1 >= 0 && j+1 < C) && board[i-1][j+1] ? 1 : 0;
            cnt += (j-1 >= 0) && board[i][j-1] ? 1 : 0;
            cnt += (j+1 < C) && board[i][j+1] ? 1 : 0;
            cnt += (i+1 < R && j-1 >= 0) && board[i+1][j-1] ? 1 : 0;
            cnt += (i+1 < R) && board[i+1][j] ? 1 : 0;
            cnt += (i+1 < R && j+1 < C) && board[i+1][j+1] ? 1 : 0;
        return cnt;    
    }
    
};
    // 1 surrounded by less than 2 1s becomes 0
    // 1 surrounded by 2 or 3 1s stays 1
    // 1 surrounded by more than 3 1s becomes 0
    // 0 surrounded by 3 1s becomes 1

/*i-1,j-1         i-1,j   i-1,j+1
i,j-1           i,j     i,j+1
i+1,j-1        i+1,j   i+1, j+1*/