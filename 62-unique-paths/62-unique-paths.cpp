class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(row == 0 && col == 0) continue;
                
                    int up = 0, left = 0;
                    if(row - 1 >= 0) up = dp[row-1][col];
                    if(col -1 >= 0) left = dp[row][col-1];
                    
                    dp[row][col]  = up + left;
                
            }
        }
        
        return dp[m-1][n-1];
    }
private: 
    int findPaths(int m, int n, int currR, int currC, vector<vector<int>>& dp) {
        if(currR == m-1 && currC == n-1) {
            return 1;
        } else if(currR == m || currC == n) {
            return 0;
        }
        
        if(dp[currR][currC] != -1) return dp[currR][currC];
        return dp[currR][currC] = findPaths(m, n, currR+1, currC, dp) + findPaths(m, n, currR, currC+1, dp);
    }
};