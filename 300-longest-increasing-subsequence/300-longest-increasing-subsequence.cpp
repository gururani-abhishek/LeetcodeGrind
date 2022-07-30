class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //instead of passing huge prev number, using which it'll be hard to memoize the solution
        //i'm passing, the idx of previous number.
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        //during memoization I did coordinate shifting, so
        //every index for prev_idx will be represented by a plus 1
        for(int idx = n-1; idx >= 0; idx--) {
            for(int prev_idx = -1; prev_idx < n; prev_idx++) {
                
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                    int takeIt = 1 + dp[idx +1][idx+1];
                    int notPickIt = dp[idx +1][prev_idx+1];

                    dp[idx][prev_idx + 1] = max(takeIt, notPickIt);
                    continue;
                }


                dp[idx][prev_idx + 1] = dp[idx +1][prev_idx+1];                
                
            }
        }
        
        return dp[0][-1 + 1];
    }
    
};