class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //there will be three states : buy, sell, cooldown.
        //there's no restriction on how many stocks you can buy.
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        
        for(int state = 0; state < 3; state++) {
            dp[n][state] = 0;
        }
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int state = 0; state < 3; state++) {
                if(state == 0) {
                    int buy = -1*prices[idx] + dp[idx +1][1];
                    int nbuy = dp[idx + 1][0];

                    dp[idx][state] = max(buy, nbuy);
                    continue;
                }
        
                if(state == 1) {
                    int sell = prices[idx] + dp[idx + 1][2];
                    int nsell = dp[idx + 1][1];

                    dp[idx][state] = max(sell, nsell);
                    continue;
                }

                //state = 2, cooldown

                dp[idx][state] = dp[idx + 1][0];
            }
        }
        
        
        return dp[0][0];
    }

};