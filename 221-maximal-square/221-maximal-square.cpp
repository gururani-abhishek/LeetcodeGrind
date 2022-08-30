class Solution {
public:
    // top down dp approach : 
    // tc : O(n*n) sc : O(n*n)
    
    // there's an intuitive dp solution for this as well : 
    // the number of squares I can create on the top row and left col, are already equal to the 
    // 1s or 0s each cell has
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(); // row size and col size
         
        vector<vector<int>> dp(n, vector<int> (m, 0));
        int side = 0;// side will hold the side of max area square: 

        
        // defining base case for the top row : 
        for(int c = 0; c < m; c++) {
            if(matrix[0][c] == '1') {
                dp[0][c] = 1;
                side = 1;
            }
        }
        
        // defining base case for the left col : 
        for(int r = 0; r < n; r++) {
            if(matrix[r][0] == '1') {
                dp[r][0] = 1;
                side = 1;
            }
        }
        
        for(int r = 1; r < n; r++) {
            for(int c = 1; c < m; c++) {
                
                if(matrix[r][c] == '0') dp[r][c] = 0;
                else {
                    dp[r][c] = 1 + min({dp[r-1][c-1], dp[r-1][c], dp[r][c-1]});
                }
                
                side = max(side, dp[r][c]);
            }
        }
        
       
        return side * side;
    
    }
};


// but for any cell( x, y) if it's a '1', it can be a square of size 1 or it can be part of squares
// before it.

// 1 1 
// 1 1    with this I can create a square of size 2

// 1 1
// 1 0    with this I can't create a square of size 2

// 1 1 
// 0 1    with this I can't create a square of size 2


// 1 0
// 0 1    with this I can't create a square of size 2