class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int ans, oneStepBefore = 2, twoStepBefore = 1;
        
        for(int i=3; i<=n; i++) {
            ans = oneStepBefore + twoStepBefore;
            twoStepBefore = oneStepBefore;\
            oneStepBefore = ans;
        }
        
        return ans;
    }
    
// private: 
    
//     int count(int n, vector<int>& dp) {
        
//         //base cases
//         if(n == 0) return 1;
//         if(n < 0) return 0;
        
        
//         if(dp[n] != -1) return dp[n];
//         return dp[n] = (count(n-1, dp) + count (n-2, dp));
        
//     }
};