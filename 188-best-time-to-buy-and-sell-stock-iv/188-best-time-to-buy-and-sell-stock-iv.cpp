class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return create(prices, 0, 0, k, dp);
    }
    
private:
    
    int create(vector<int>& prices, int idx, int bought, int limit, vector<vector<int>>& dp) {
        if(idx == prices.size()) return 0;
        if(bought == 2*limit) return 0;

        if(dp[idx][bought] != -1) return dp[idx][bought];
        //bought = 0, 2, 4... where I can buy the stocks.
        if(bought % 2 == 0) {
            int buy = -1* prices[idx] + create(prices, idx + 1, bought+1, limit, dp);
            int nbuy = create(prices, idx + 1, bought, limit, dp);
        
            return dp[idx][bought] = max(buy, nbuy);
        }
        
        //bought = 1, 3, 5...where  I can sell the stocks.
        int sell = prices[idx] + create(prices, idx + 1, bought + 1, limit, dp);
        int nsell = create(prices, idx + 1, bought, limit, dp);
        
        return dp[idx][bought] = max(sell, nsell);
    }
};