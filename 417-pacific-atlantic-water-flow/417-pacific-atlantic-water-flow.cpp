class Solution {
public:
    vector<vector<int>> pacific, atlantic;
    vector<vector<int>> ans;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        pacific = atlantic = vector<vector<int>> (n, vector<int> (m, 0));
    
        for(int i=0; i<n; i++) dfs(heights, pacific, i, 0), dfs(heights, atlantic, i, m-1);
        for(int j = 0; j<m; j++) dfs(heights, pacific, 0, j), dfs(heights, atlantic, n-1, j);
        
        return ans;
    }
    
private: 
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j) {
        if(visited[i][j]) return;
        visited[i][j] = 1;
        
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
        
        if(i-1 >= 0 && heights[i][j] <= heights[i-1][j]) dfs(heights, visited, i-1, j);
        if(i+1 < heights.size() && heights[i][j] <= heights[i+1][j]) dfs(heights, visited, i+1, j);
        if(j+1 < heights[0].size() && heights[i][j] <= heights[i][j+1]) dfs(heights, visited, i, j+1);
        if(j-1 >= 0 && heights[i][j] <= heights[i][j-1]) dfs(heights, visited, i, j-1);
        
    }
};

//          {i-1, j}
// {i, j-1} {i, j} {i, j+1}
//          {i+1, j}