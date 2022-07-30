class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return create(prices, fee, 0, 0, dp);
    }
    
private: 
    int create(vector<int>& prices, int fee, int idx, int bought, vector<vector<int>>& dp) {
        if(idx == prices.size()) return 0;
        
        
        if(dp[idx][bought] != -1) return dp[idx][bought];
        if(bought) {
            int sell = prices[idx] - fee + create(prices, fee, idx + 1, !bought, dp);
            int nsell = create(prices, fee, idx + 1, bought, dp);
        
            return dp[idx][bought] = max(sell, nsell);
        }
        
        int buy = -prices[idx] + create(prices,  fee, idx+1, !bought, dp);
        int nbuy = create(prices, fee, idx + 1, bought, dp);
        
        return dp[idx][bought] = max(buy, nbuy);
        
    }
};