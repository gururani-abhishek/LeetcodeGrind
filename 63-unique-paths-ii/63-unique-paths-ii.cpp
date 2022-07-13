class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = (obstacleGrid[0][0] != 1);
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                
                if(row == 0 && col == 0) continue;
                else {
                    int up = 0, left = 0;
                    if(row > 0 && obstacleGrid[row][col] != 1) up = dp[row-1][col];
                    if(col > 0 && obstacleGrid[row][col] != 1) left = dp[row][col-1];
                    
                    dp[row][col] = left + up;
                }
            }
        }
    
        return dp[n-1][m-1];
    }
    
private: 
    int findPaths(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if(row == 0 && col == 0 && grid[row][col] != 1) return 1;
        else if(row < 0 || col < 0 || grid[row][col] ==  1) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        return  dp[row][col] = findPaths(grid, row-1, col, dp) + findPaths(grid, row, col-1, dp);
    }
};
