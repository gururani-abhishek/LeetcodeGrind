class Solution {
public:
    
    // tc : O(n * (n + m))
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(); // row and col sizes
        
        // fix the row to 0, and perform a dfs diagonally
        for(int col = 0; col < m; col++) {
            vector<int> diagElements; // create a vector to store diagonal elements
            fillVector(mat, 0, col, diagElements); // fill it with the help of a DFS
            sort(diagElements.begin(), diagElements.end()); // sort it, i.e. sort the diagonal
            fillMatrix(mat, 0, col, diagElements, 0); // fill that diagonal back in the matrix
        }
        
        // you've already performed for (0, 0), hence start with (1, 0)
        // fix the col and perform dfs diagonally 
        for(int row = 1; row < n; row++) {
            vector<int> diagElements; // this is where I'll store all the elements of this diagonal
            fillVector(mat, row, 0, diagElements); // dfs to fill the diagElements
            sort(diagElements.begin(), diagElements.end()); // sort it
            fillMatrix(mat, row, 0, diagElements, 0);
        }

        return mat;
    }
    
private: 
    void fillVector(vector<vector<int>> &mat, int r, int c, vector<int> &diagElements) {
        if(r >= mat.size() || c >= mat[0].size()) return; // base case
        diagElements.push_back(mat[r][c]); // fill the vector
        fillVector(mat, r + 1, c + 1, diagElements); // call next diagonal element
    }
    
    void fillMatrix(vector<vector<int>> &mat, int r, int c, vector<int> &diagElements, int idx) {
        if(r >= mat.size() || c >= mat[0].size()) return; // base case
        mat[r][c] = diagElements[idx];
        fillMatrix(mat,r +1, c +1, diagElements, idx+1);
    }
};



// what if I do this : 

// 1 2 5 4          // 1 2 2 3
// 3 5 7 9   -->    // 3 4 4 5
// 8 3 4 2          // 5 7 8 9

//  this won't work because  the question explicitly asks to sort diagonals of the 
// given matrix. 
 
 