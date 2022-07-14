class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<int> prev(triangle.size(), 0);
        
        for(int row = 0; row < triangle.size(); row++) {
            vector<int> curr(triangle.size(), 0);
            
            for(int idx = 0; idx < triangle[row].size(); idx++) {
                if(row == 0 && idx == 0) curr[0] = triangle[0][0];
                else {
                    int up = triangle[row][idx], upBefore = triangle[row][idx];
                    
                    
                    if(idx < triangle[row-1].size()) up += prev[idx];
                    else up = INT_MAX;
                    if(idx > 0) upBefore += prev[idx-1];
                    else upBefore = INT_MAX;
                    
                    curr[idx] = min(up, upBefore);
                }
                
            }
            prev = curr;
        }
    
        int ans = INT_MAX;
        for(int i=0; i<prev.size(); i++) {
            ans = min(prev[i], ans);
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