class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findPaths(obstacleGrid, n - 1, m - 1, dp);
    }
    
private: 
    int findPaths(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if(row == 0 && col == 0 && grid[row][col] != 1) return 1;
        else if(row < 0 || col < 0 || grid[row][col] ==  1) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        return  dp[row][col] = findPaths(grid, row-1, col, dp) + findPaths(grid, row, col-1, dp);
    }
};
