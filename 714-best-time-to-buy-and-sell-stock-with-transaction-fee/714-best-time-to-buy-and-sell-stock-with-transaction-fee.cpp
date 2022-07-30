class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int bought = 0; bought <2; bought++) {
                if(bought) {
                    int sell = prices[idx] - fee + dp[idx + 1][!bought];
                    int nsell = dp[idx + 1][bought];

                    dp[idx][bought] = max(sell, nsell);
                    continue;
                }
        
                int buy = -prices[idx] + dp[idx+1][!bought];
                int nbuy = dp[idx + 1][bought];

                dp[idx][bought] = max(buy, nbuy);
            }
        }
        
       return dp[0][0];
    }
    
};