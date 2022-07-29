class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        //base case;
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int bought=0; bought<2; bought++) {
                if(bought) {
                    int sell = prices[idx] + dp[idx+1][0];
                    int nsell = dp[idx + 1][bought];

                    dp[idx][bought] = max(sell, nsell);
                    continue;
                }
        
        
            int buy = -1*prices[idx] + dp[idx+1][1];
            int nbuy = dp[idx+1][bought];
            
            dp[idx][bought] = max(buy, nbuy);
                
            }
        }
        
        
        return dp[0][0];
    }
    
};