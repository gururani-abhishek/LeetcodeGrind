class Solution {
public:
    // time complexity O(n*m*3^lengthOfWord)
    // space comeplexity O(n*m*4^lenghtOfWord)
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(check(board, i, j, word)) {
                    return true;
                } 
            }
        }
        
        return false;
    }
    
private: 
    bool check(vector<vector<char>>& board, int i, int j, string& word) {
        if(!word.size()) return true;        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0]) return false;
        
        char c = board[i][j];
        board[i][j] = '*'; //to remember that i, j has already been used 
        string s= word.substr(1);//will remove the first element from our string
        bool flag = (check(board, i+1, j, s) || check(board, i-1, j, s) || check(board, i, j-1, s) || check(board, i, j+1, s));
        
        board[i][j] = c; //for other locations, plus it's an important practice to change your data back to original.
        
        return flag;
        
    }
};

//initially I was trying to do it using subset technique, but that would be so 
//inefficient, here we're already provided with the word string,
//we can use it and make it a more efficient solution

