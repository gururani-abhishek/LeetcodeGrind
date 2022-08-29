class Solution {
public:
    // tc : O(n + 1) ~ O(n) looping for n times, plus one for worst case stack 
    
    int largestRectangleArea(vector<int>& heights) {
        
        // find width using monotonic stack, and width is a function of indcies
        // mono will store only indices
        stack<int> mono;
        
        int n = heights.size(); // size of my array
        
        // idea is to form monotonic stack, which will give bar heights in increasing order
        // before any index.
        
        vector<int> leftBoundary(n), rightBoundary(n);
        for(int idx = 0; idx < n; idx++) {
            // equal to as well, because i want recent elements in increasing order. 
            while(!mono.empty() && heights[idx] <= heights[mono.top()]) {
                mono.pop();
            }    
    
            // after this I'll be knowing what is going to be the left index 
            // that has a height lesser than my  current index. 
            
            // there might be no such element -> stack empty
            if(mono.empty()) leftBoundary[idx] = 0;
            else leftBoundary[idx] = mono.top() + 1;
            
            mono.push(idx);
            
        }
        
        // gonna reuse my stack, so need to empty it first : 
        while(!mono.empty()) mono.pop();
        
        for(int idx = n-1; idx >=0; idx--) {
            while(!mono.empty() && heights[idx] <= heights[mono.top()]) {
                mono.pop();
            }
            
            if(mono.empty()) rightBoundary[idx] = n-1;
            else rightBoundary[idx] = mono.top() -1;
        
            mono.push(idx);
        }
        
        
        int ans = INT_MIN;
        
        // run through boundaries -> find width
        // width = right - left + 1
        for(int idx = 0; idx < n; idx++) {
            int width = rightBoundary[idx] - leftBoundary[idx] + 1;
            int height = heights[idx];
            
            ans = max(ans, width * height);
        }
        
        return ans;

    }
};

// [2, 1, 5, 6, 2, 3] -> heights of bars in the histogram
// find out max rectangle area in this histogram

// can you elaborate on what a rectangle here is? 

// power of cumulation
// -> 2 (height * width) = (2 * 1) = 2sq units
// -> 1 (height * width) = (1 * 6) = 6sq units
// -> 5 (5 * 2) = 10sq units
// -> 6 (6 * 1) = 6sq units
// -> 2 (2 * 4) = 8sq units
// -> 3 (3 * 1) = 3sq untis

/* -> O(n * n), if I'm storing the boundaries -> O(n + n)
for every bar
    I'll stretch to the left and find max width it can spread to
    I'll stretch to the right and find max widht it can spread to
    
    will sum up width and multiply with height
    and greedily find the max.
end for

return max;
*/

// another intution : 

// suppose I'm at any bar ->
// boundary to the left will be the bar with height less than current bar height
// same will be the case for right boundary 

// monotonic stack : 2, 3, 1, 2, 3, 5 -> 1, 2, 3, 5