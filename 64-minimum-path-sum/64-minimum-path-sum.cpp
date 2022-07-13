class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minpathsum(grid, n-1, m-1, dp);
    }
private: 
    int minpathsum(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if(row == 0 && col == 0) return grid[row][col];
        else if(row < 0 || col < 0) return INT_MAX;
        
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = grid[row][col] + min(minpathsum(grid, row-1, col, dp), minpathsum(grid,  row, col-1, dp));
        
    }
};