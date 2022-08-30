class Solution {
public:
    // tc : O(n * (n + 1)) ~ O(n * n) 
    // sc : O(n + n + n + n) ~ O(n)
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prefixHeights(m, 0); // will store the prefix heights of cols, for each level.
    
        int ans = INT_MIN;
        
        // traverse the matrix row wise(level wise) : 
        for(int r = 0; r < n; r++) {
            
            // for this level I'll update my prefixHeights : 
            for(int c = 0; c < m; c++) {
                if(matrix[r][c] == '1') prefixHeights[c] += 1; // if it's a '1', cumulative height can be added
                else prefixHeights[c] = 0; // if it's a zero, height will be discontinuous, 
                // hence heights[c] = 0
            }
            
            ans = max(ans, findLargestSquare(prefixHeights)); // choose max square area out of all the levels.
        }
        
        return ans;
    
    }
    
private : 
        int findLargestSquare(vector<int> &heights) {
            stack<int> mono; // monotonic stack, increasing order.
            int n = heights.size(); // number of bars 
            
            // these vectors will store left and right boundary for each bar :  
            vector<int> left(n), right(n);
            
            // traversing from left to right : 
            for(int idx = 0; idx < n; idx++) {
                // maintain monotonic stack for this newly added idx(bar) : 
                while(!mono.empty() && heights[idx] <= heights[mono.top()]) mono.pop();
                
                // to the left of this bar, there's no bar that has a height samller than it
                if(mono.empty()) left[idx] = 0; // hence it's left boundary will be leftmost end of the array(0 idx);
                else left[idx] = mono.top() + 1; // so there exists an element to the left of this bar that has a 
                // height smaller than the bar height,  hence idx next to it will be our left boundary
                
                
                // push in the new idx : 
                mono.push(idx);
            }
            
            // because I'll be reusing this mono stack, I need to empty it before the usage : 
            while(!mono.empty()) mono.pop();
            
            // setting up the right boundaries : 
            for(int idx = n-1; idx >= 0; idx--) {
                while(!mono.empty() && heights[idx] <= heights[mono.top()]) mono.pop();
                
                if(mono.empty()) right[idx] = n-1;
                else right[idx] = mono.top() -1;
                
                mono.push(idx); 
            }
            
            // find max area of square : 
            // till this step it's same as largest rectangle in a histogram, or maximal rectangle question
            // this being a square now the difference will arise in calculating the area :
            
            int ans = INT_MIN;
            for(int idx =0; idx <n; idx++) {
                int width = right[idx] - left[idx] + 1;
                int height = heights[idx];
                
                 // this is the entire new logic : 
                // find the length of square's side = n
                int n = min(width , height); // it'll be minimum of width and the height : 
                ans = max(ans, n * n); // find the max area that can formed using all the bars 
            }
            
            return ans;
        }
};

// 1, 0, 1, 0, 0 -> (width = 1, height = 1) n = 1 areaOfLargestSquare = 1
// 2, 0, 2, 1, 1 -> (width = 3, height = 1) n = 1 areaOfLargestSquare = 1
// 3, 1, 3, 2, 2 -> (width = 3, height = 2) n = 2 areaOfLargestSquare = 4
// 4, 0, 0, 3, 0 -> (width = 1, height = 4) n = 1 areaOfLargestSquare = 1
// max = 4, that will be my answer.
// looks very similar to maximal rectangle question, except while choosing the 
// width and the height, I'll have to choose 'n' for square such that it is min of
// width  and height.