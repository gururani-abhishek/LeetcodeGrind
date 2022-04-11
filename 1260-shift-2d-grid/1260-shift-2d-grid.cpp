class Solution {
public:
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        shift(grid, k);
        return grid;
    }
    
private: 
    void shift(vector<vector<int>>& grid, int k) {
        if(k == 0) return;
        
        int r = grid.size(), c = grid[0].size();
        
        vector<int> lastColumn;
        lastColumn.push_back(grid[r-1][c-1]);
        
        for(int i =0; i<r-1; i++) 
            lastColumn.push_back(grid[i][c-1]);

        

        for(int i=0; i<r; i++) {
            for(int j = c-1; j>0; j--) {
                grid[i][j] = grid[i][j-1];
            }
        }
        
        for(int i = 0; i<r; i++) {
            grid[i][0] = lastColumn[i];
        }
        
        shift(grid, k-1);
    }
};