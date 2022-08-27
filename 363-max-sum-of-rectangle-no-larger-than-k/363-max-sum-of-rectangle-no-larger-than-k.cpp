class Solution {
public:
    // tc : cols * cols * rows * log(rows)
    // this implementation is very thought provoking and beautiful, I found it on yt.
    // I'm cleverly implementing the BF idea, by analysing all the rectangles that I can form.
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        // my rectangle refers to all the BF rectangles that I'm exploring to find my final rectangle.
        
        //rowSize and colSize
        int rows = matrix.size(), cols = matrix[0].size();
        
        // left : leftMostCellOfMyRectangle -> first cell(0 -> cols-1)
        // right : rightMostCellOfMyRectangle -> last cell((left ->  cols-1), with 'left' it will determine the width of my rectangle
        // rowSum represents the row wise sum of my rectangle -> with the help of prefix sum I can check all the combinations of this(i.e. vaious height rectangles)
        int ans = INT_MIN;
        for(int left = 0; left < cols; left++) {
            vector<int> rowSum(rows); // rowWiseSum for all the rectangles.
            for(int right = left; right < cols; right++) {
                
                //to sum rowSum for all the rows 
                for(int row = 0; row < rows; row++) {
                    rowSum[row] += matrix[row][right];
                }
                
                // will store row sum in cumulative fashion.
                set<int> cumulativeRowSum = {0}; // 0 so that it can also pair with itself. 
                // with the help of prefix sum, I can simply try out all the combination of heights.
                
                int sum = 0;  // cumulative sum of rowSum.
                for(auto u: rowSum) {
                    sum += u; // c[j] is sum;
                    // c[j] - c[i] <= k, that's what I've to find or
                    // c[j] -  k <=  c[i], so I can simply find c[i],
                    // if found, then c[j] - c[i] could be my answer, c refers to cumulative sum;
                    
                   // sum - k is c[i]
                    auto it = lower_bound(cumulativeRowSum.begin(), cumulativeRowSum.end(), sum - k);
                    if(it != cumulativeRowSum.end()) {
                        ans = max(ans, sum - *it);
                    }
                    
                    cumulativeRowSum.insert(sum);
                }
                
                
            }
            
        }
        
        return ans;
    }
};

// return the max sum of a rectangle with sum less than or equal to k
// My first intution was to check all such rectangles and sum their elements up,
// the one with sum just less than equal to k will be our answer. 
// so out of all those rectangles we have to choose one with max element sum, 
// that is less than or equal to k.
// but I have no idea how to implement it 
