class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], h = matrix[n-1][n-1];
        
        while(l < h) {
            int mid = l + (h -l)/2;
            if(countLessOrEqual(matrix, mid) >= k) h = mid;
            else l = mid + 1;
        }

        return l;
    }
private: 
    int countLessOrEqual(vector<vector<int>>& matrix, int key) {
        int count = 0, n = matrix.size();
        //int j = n-1;
        for(int i=0; i<n; i++) {
            // while(j>=0 && matrix[i][j] >key) j--;
            // count += (j+ 1);
            for(int j = 0; j<n && matrix[i][j] <= key; j++) count++;
        }
        return count;
    }
};