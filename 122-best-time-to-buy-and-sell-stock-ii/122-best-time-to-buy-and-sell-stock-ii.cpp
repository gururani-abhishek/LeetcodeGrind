class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return create(prices, 0, 0, dp);
    }
    
private: 
    int create(vector<int>& prices, int bought, int idx, vector<vector<int>>& dp) {
        if(idx == prices.size()) return 0;
        
        if(dp[idx][bought] != -1) return dp[idx][bought];
            if(bought) {
                int sell = prices[idx] + create(prices, false, idx+1, dp);
                int nsell = create(prices, bought, idx + 1, dp);

                return dp[idx][bought] = max(sell, nsell);
            }
        
        
            int buy = -1*prices[idx] + create(prices, true, idx+1, dp);
            int nbuy = create(prices, bought, idx + 1, dp);
            
            return dp[idx][bought] = max(buy, nbuy);
    }
};