class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>dp (m, 0);
        
        for(int row=0; row<n; row++) {
            vector<int> cur(m, 0);
            for(int col=0; col<m; col++) {
                if(row == 0 && col == 0) cur[0] = grid[0][0];
                else {
                    int left = 0, up = 0;
//                     if(row > 0) up = dp[row-1][col];
//                     else up = INT_MAX;
                     
                    up = row > 0 ? dp[col] : INT_MAX;
                    left = col > 0 ? cur[col -1] : INT_MAX;
                    
                    cur[col] = grid[row][col] + min(left, up);
                }
            }
            dp = cur;
        }
        
        return dp[m-1];
    }

};