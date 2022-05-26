class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    explore(grid, i, j);
                }        
            }
        }
        
        return ans;
    }
    
    
private:
    void explore(vector<vector<char>>& grid, int i , int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        
        if(grid[i][j] == '1') {
            grid[i][j] = '0';
            explore(grid, i, j+1);
            explore(grid, i, j-1);
            explore(grid, i-1, j);
            explore(grid, i+1, j);
        }
    }
};