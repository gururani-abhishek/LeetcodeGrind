class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val = 1; //will range till n * n
        int c1 = 0, c2 = n-1, r1 = 0, r2 = n-1;
        // will also act like my boundary and starting postion
        
        
        vector<vector<int>> ans(n, vector<int> (n, 0));
        
        while(c1 <= c2 && r1 <= r2) {
            //row fixed, left to right traversal
            for(int j = c1; j<=c2; j++) ans[r1][j] = val++;
            r1++;
            
            //column fixed, top to bottom traversal
            for(int i = r1; i<=r2; i++) ans[i][c2] = val++;
            c2--;
            
            //row fixed, right to left traversal
            for(int j = c2; j>=c1; j--) ans[r2][j] = val++;
            r2--;
            
            //column  fixed, bottom to top traversal
            for(int i=r2; i>=r1; i--) ans[i][c1] = val++;
            c1++;
            
        }
        
        return ans;
        
    }
};


/*

 ________
|        |      
|        |
|        |
|        | 
|________|

after one round it's size will decrease by 1 from all the sides, 

*/