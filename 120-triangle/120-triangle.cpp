class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        dp[0][0] = triangle[0][0];
        
        for(int row = 0; row < triangle.size(); row++) {
            for(int idx = 0; idx < triangle[row].size(); idx++) {
                if(row == 0 && idx == 0) continue;
                else {
                    int up = triangle[row][idx], upBefore = triangle[row][idx];
                    
                    
                    if(idx < triangle[row-1].size()) up += dp[row-1][idx];
                    else up = INT_MAX;
                    if(idx > 0) upBefore += dp[row-1][idx-1];
                    else upBefore = INT_MAX;
                    
                    dp[row][idx] = min(up, upBefore);
                }
                
            }
        }
    
        int ans = INT_MAX;
        for(int i=0; i<triangle[triangle.size()-1].size(); i++) {
            ans  = min(ans, dp[triangle.size()-1][i]);
        }
        
        return ans;
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