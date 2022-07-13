class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        dp[0][0] = grid[0][0];
        
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(row == 0 && col == 0) continue;
                else {
                    int left = 0, up = 0;
//                     if(row > 0) up = dp[row-1][col];
//                     else up = INT_MAX;
                     
                    up = row > 0 ? dp[row-1][col] : INT_MAX;
                    left = col > 0 ? dp[row][col -1] : INT_MAX;
                    
                    dp[row][col] = grid[row][col] + min(left, up);
                }
            }
        }
        
        return dp[n-1][m-1];
    }

};