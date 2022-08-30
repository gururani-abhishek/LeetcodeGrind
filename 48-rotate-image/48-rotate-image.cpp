class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size(); // rowSize and colSize;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(r >= c) continue;
                swap(matrix[r][c], matrix[c][r]);
            }
            
            reverse(matrix[r].begin(), matrix[r].end());
        }
        
    }
};
 

// find adjacent matrix -> and reverse every row -> bam!!
// problem with this approach : 
// how to do that in-place? 