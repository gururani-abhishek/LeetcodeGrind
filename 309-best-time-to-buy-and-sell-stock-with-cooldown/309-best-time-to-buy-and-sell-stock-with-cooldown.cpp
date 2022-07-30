class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //there will be three states : buy, sell, cooldown.
        //there's no restriction on how many stocks you can buy.
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return create(prices, 0, 0, dp);
    }
    
private: 
    int create(vector<int>& prices, int idx, int state, vector<vector<int>>& dp) {
        if(idx == prices.size()) return 0;
        
        if(dp[idx][state] != -1) return dp[idx][state];
        if(state == 0) {
            int buy = -1*prices[idx] + create(prices, idx +1, 1, dp);
            int nbuy = create(prices, idx + 1, 0, dp);
            
            return dp[idx][state] = max(buy, nbuy);
        }
        
        if(state == 1) {
            int sell = prices[idx] + create(prices, idx + 1, 2, dp);
            int nsell = create(prices, idx + 1, 1, dp);
            
            return dp[idx][state] = max(sell, nsell);
        }
        
        //state = 2, cooldown
        
        return dp[idx][state] = create(prices, idx + 1, 0, dp);
    }
};