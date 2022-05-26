class Solution {
public:
    
    vector<vector<int>> pacific, atlantic;
    vector<vector<int>> ans;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        pacific = atlantic = vector<vector<int>> (n, vector<int> (m, 0));
        
        for(int i = 0; i<n; i++) explore(heights, i, 0, pacific), explore(heights, i, m-1, atlantic);
        for(int j = 0; j<m; j++) explore(heights, 0, j, pacific), explore(heights, n-1, j, atlantic);
    
    
        return ans;
    }
    
private: 
    void explore(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& visited) {
        if(visited[i][j]) return;
        visited[i][j] = 1;
        
        if(pacific[i][j] && atlantic[i][j]) ans.push_back(vector<int> {i, j});
        
        if(i+1 < heights.size() && heights[i][j] <= heights[i+1][j]) explore(heights, i+1, j, visited);
        if(i-1 >= 0 && heights[i][j] <= heights[i-1][j]) explore(heights, i-1, j, visited);
        if(j+1 < heights[0].size() && heights[i][j] <= heights[i][j+1]) explore(heights, i, j+1, visited);
        if(j-1 >= 0 && heights[i][j] <= heights[i][j-1]) explore(heights, i, j-1, visited);
    }
};