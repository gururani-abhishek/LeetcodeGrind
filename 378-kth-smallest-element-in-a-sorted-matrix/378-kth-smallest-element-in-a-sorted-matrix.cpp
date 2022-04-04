class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix[matrix.size()-1][matrix[0].size() -1];
        while(l < r) {
            int mid = l + (r -l)/2;
            
            if(countElements(matrix, mid) >= k) r = mid; 
            else l = mid + 1;
        }
    
        return l;
    }
private: 
    int countElements(vector<vector<int>> matrix, int k) {
        int count = 0;
        int j = matrix[0].size() -1;
        for(int i=0; i<matrix.size(); i++) {
            while(j >= 0 && matrix[i][j] > k) j--;
            count += j + 1;
        }
        return count;
    }
};