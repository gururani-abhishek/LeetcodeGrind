class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return minTB(triangle, 0, 0, dp);
    }
    
    
private: 
    int minTB(vector<vector<int>>& triangle, int row, int idx, vector<vector<int>>& dp) {
        if(row == triangle.size() -1) return triangle[row][idx];
        // else if(idx > triangle[row].size()-1) return INT_MAX;
        
        
        if(dp[row][idx] != -1) return dp[row][idx];
        
        int down = triangle[row][idx], downFront = triangle[row][idx];
        down += minTB(triangle, row+1,idx, dp);
        downFront += minTB(triangle, row+1, idx+1, dp);
        
        return dp[row][idx] = min(down, downFront);
    
    
    }
};