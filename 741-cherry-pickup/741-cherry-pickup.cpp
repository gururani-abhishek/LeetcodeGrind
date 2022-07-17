class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        //maxCP(grid, row1, col1, col2);
        //could have been maxCP(grid, row1, col1, row2, col2); 
        //but that would have been unnecessary, 
        //as, row1 + col1 = row2 + col2;
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return max(0, maxCP(grid, 0, 0, 0, n, m, dp));
    }

private: 
    int maxCP(vector<vector<int>>& grid, int row1, int col1, int col2, int n, int m, vector<vector<vector<int>>>& dp) {
        int row2 = row1 + col1 -col2;
        
        //edge case
        if(row1 > n-1 || col1 > m-1 || row2 > n-1 || col2 > m-1 || grid[row1][col1] == -1 || grid[row2][col2] == -1) return -1e9;
        //base case
        if(row1 == n-1 && col1 == m-1 && row2 == n-1 && col2 == m-1) return grid[row1][col1];
        
        
        if(dp[row1][col1][col2] != -1) return dp[row1][col1][col2];
        //there will be a total of four movements
        int dd = maxCP(grid, row1+1, col1, col2, n, m, dp);
        int dr = maxCP(grid, row1+1, col1, col2+1, n, m, dp);
        int rd = maxCP(grid, row1, col1+1, col2, n, m, dp);
        int rr = maxCP(grid, row1, col1+1, col2+1, n, m, dp);
        
        //movement that is resulting in max cherry picks
        int mxMov = max({dd, dr, rd, rr});
        
        //adding current value of cherry rob1  and rob2 would be at
        if(row1 == row2 && col1 == col2) mxMov += grid[row1][col1];
        else mxMov += grid[row1][col1] + grid[row2][col2];
        
        
        return dp[row1][col1][col2] = mxMov;
    }
};

