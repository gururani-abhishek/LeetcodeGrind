class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = matrix.size();
        
        for(int i=0; i<n; i++) { 
            for(int j=0; j<n; j++) {
                minHeap.push(matrix[i][j]);
                if(minHeap.size() > n*n-k+1) minHeap.pop();
                
            }
        }
        
        return minHeap.top();
    }
};

//tc: O(n*n*log(n-k+1)) //building a heap of size 'n-k+1'
//sc: O(n-k+1) //heap of size k