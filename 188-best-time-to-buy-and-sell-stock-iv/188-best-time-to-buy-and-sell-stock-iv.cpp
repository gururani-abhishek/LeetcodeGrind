class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        for(int bought = 0; bought <= 2*k; bought++) {
            dp[n][bought] = 0;
        }
        
        for(int idx = 0; idx <= n; idx++) {
            dp[idx][2*k] = 0;
        }
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int bought = 2*k-1; bought >= 0; bought--) {
                 if(bought % 2 == 0) {
                    int buy = -1* prices[idx] + dp[idx + 1][bought+1];
                    int nbuy = dp[idx + 1][bought];

                    dp[idx][bought] = max(buy, nbuy);
                    continue;
                 }
        
        //bought = 1, 3, 5...where  I can sell the stocks.
                int sell = prices[idx] + dp[idx + 1][bought + 1];
                int nsell = dp[idx + 1][bought];

                dp[idx][bought] = max(sell, nsell);
            }
        }
        
        
        
        return dp[0][0];
    }
    
};