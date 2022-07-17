class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        //space optimisation as only prev row is being used I can simply take 2 2d arrays, to store curr and prev data. 
        //tc : O(n*m*m*9)
        //sc : O(m*m)
        vector<vector<int>> prev(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));
        
        for(int j1 = 0; j1<m; j1++) {
            for(int j2 = 0; j2<m; j2++) {
                if(j1 == j2) prev[j1][j2] = grid[n-1][j1]; 
                else prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i=n-2; i>=0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    
                    int mx = -1e9;
                    for(int dj1 = -1; dj1 <2; dj1++) {
                        for(int dj2 = -1; dj2 <2; dj2++) {
                            
                            int mov = (j1+dj1 >= 0 && j1+dj1 <= m-1 && j2+dj2 >=0 && j2+dj2 <= m-1) ? prev[dj1+j1][dj2+j2] : -1e9; 
                            if(j1 == j2) mov += grid[i][j1];
                            else mov += grid[i][j1] + grid[i][j2];
                            
                            mx = max(mov, mx);
                        }
                    }
                    
                    
                    curr[j1][j2] = mx;
                }
            }
            prev = curr;
        }
        
        
         return prev[0][m-1];   
        
        
    }
};