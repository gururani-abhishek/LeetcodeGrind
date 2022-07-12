class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPaths(m, n, 0, 0, dp);
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