class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minStockPriceTillToday = INT_MAX;
        int profit = 0;
        
        for(int i=0; i<prices.size(); i++) {
            int profitTemp = prices[i] - minStockPriceTillToday;
            profit = max(profit, profitTemp);
            minStockPriceTillToday = min(minStockPriceTillToday, prices[i]);
        }
    
        return profit;
    }
};