class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return maxCherryPicked(grid, 0, 0, grid[0].size() -1, dp);
    }
    
    int maxCherryPicked(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
        if(j1 < 0 || j2 < 0 || j1 > grid[0].size()-1 || j2 > grid[0].size() -1) {
            return -1e9;
        }
        
        if(i == grid.size()-1) {
            if(j1 == j2) return grid[i][j1];
            else return (grid[i][j1] + grid[i][j2]);
        }
        
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int mx = -1e9;
        for(int dj1 = -1; dj1 <2; dj1++) {
            for(int dj2 = -1; dj2 <2; dj2++) {
                if(j1 != j2) mx = max(mx, grid[i][j1] + grid[i][j2] + maxCherryPicked(grid, i+1, j1+ dj1, j2+ dj2, dp));
                else mx = max(mx, grid[i][j1] + maxCherryPicked(grid, i+1, j1+dj1, j2+dj2, dp));
            }
        }
        
        return dp[i][j1][j2] = mx;
    }
};