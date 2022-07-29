class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        return create(prices, 0, 0, dp);
    }
    
private:
    int create(vector<int>& prices, int bought, int idx, vector<vector<int>>& dp) {
        if(idx ==  prices.size()) return 0;
        
        if(dp[idx][bought] != -1) return dp[idx][bought];

        //bought = 0, bought = 2(even) -> can only buy
        //bought = 1 bought = 3(odd) -> can only sell
        //bought > 3 cannot do anything.
        
        if(bought == 4) return dp[idx][bought] = create(prices, bought, idx+ 1, dp);
        if(bought%2 == 0) {
            int buy = -1*prices[idx] + create(prices, bought+1, idx + 1, dp);
            int nbuy = create(prices, bought, idx+1, dp);
            
            return dp[idx][bought] = max(buy, nbuy);
        } 
        
        int sell = prices[idx] + create(prices, bought+1, idx +1, dp);
        int nsell = create(prices, bought, idx + 1, dp);
        
        return dp[idx][bought] = max(sell, nsell);
        
    }
};