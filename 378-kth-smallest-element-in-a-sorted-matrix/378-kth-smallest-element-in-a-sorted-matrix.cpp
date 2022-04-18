class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        int n = matrix.size();
        
        for(int i=0; i<n; i++) { 
            for(int j=0; j<n; j++) {
                maxHeap.push(matrix[i][j]);
                
                if(maxHeap.size() > k) maxHeap.pop();
            }
        }
        
        return maxHeap.top();
        
    }
};

//tc: O(n*n*log(k)) //building a heap of size 'k'
//sc: O(k) //heap of size k