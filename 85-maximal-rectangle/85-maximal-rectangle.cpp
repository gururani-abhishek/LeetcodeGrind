class Solution {
public:
    // tc : O(n * (m + 1)) ~ O(n*m) 
    // sc : O(n + n + n + n) ~ O(3n) ~ O(n) 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prefixHeights(m, 0); // will store sum of continuous heights for each level
        
        int ans = INT_MIN;
        
        // traversing for each level(row) : 
        for(int r = 0; r < n; r++) {
            // update prefixHeights(i.e. vector prefixHeights): 
            for(int c = 0; c < m; c++) {
                if(matrix[r][c] == '1') prefixHeights[c]++; // if it equals '1', it's continuous => increment on previous height
                else prefixHeights[c] = 0; // if it's '0', it's discontinuous, make the height 0.
            }
            
            // I've to treat every level's prefixHeights as bar heights of my histogram and find the largest 
            // area rectangle that can be formed. And choose the max one across all the levels.
            
            ans = max(ans, findLargestAreaRectangle(prefixHeights));
        }
        
        return ans;
        
    }

private: 
    int findLargestAreaRectangle(vector<int> &heights) {
        // monotonic stack : 
        stack<int> mono;
  
        int n = heights.size();
        vector<int> left(n), right(n);  // left and right to store boundaries for each bar to stretch, on the left and the right.
        
        // left traversal : 
        for(int idx = 0; idx < n; idx++) {
            while(!mono.empty() && heights[idx] <= heights[mono.top()]) mono.pop();
            
            // either mono is empty :
            if(mono.empty()) left[idx] = 0; // will stretch to the left most
            else left[idx] = mono.top() + 1; // top element will be smaller than the current element, boundary will be 1 index right to it.
            
            mono.push(idx); // push this one in, as this will be the next greater element after top element of the stack. 
        }
        
        // I'll be reusing my stack, so don't forget to empty it : 
        while(!mono.empty()) mono.pop();
        
        for(int idx = n-1; idx >=0; idx--) {
            while(!mono.empty() && heights[idx] <= heights[mono.top()]) mono.pop();
            
            if(mono.empty()) right[idx] = n-1; // if stack empty, no element to the right of current element is smaller than that, 
            // right boundary will stretch to the rightmost(i.e. n-1);
            else right[idx] = mono.top() -1; //else one less than the element that's just greather than it
            
            mono.push(idx);
        }
        
        
        int res = INT_MIN;
        
        for(int idx =0; idx < n; idx++) {
            int width = right[idx] - left[idx] + 1;
            int height = heights[idx];
            
            res = max(res, height* width);
        }
        
        
        return res;
        
    }
};

// I was thinking of converting entire rectangle into one histogram and applying
// "largest rectangle in a histogram" but that won't work as the heights here can be 
// discontinuous as well, like here at the base, height in column 2, 3, 5 is discontinuous


// but I'll rather apply the same approach in every level, which will be cumulation of 
// previous level heights, provided they are continuous.

/*                 prefix Heights   max rectangle area : 
level 0 (row 0) -> 1, 0, 1, 0, 0 ->         1 
level 1 (row 1) -> 2, 0, 2, 1, 1 ->         3
level 3 (row 3) -> 3, 1, 3, 2, 2 ->         6
level 4 (row 4) -> 4, 0, 0, 3, 0 ->         4

hence 6 will be the max across all levels, hence I'll return 6.


*/