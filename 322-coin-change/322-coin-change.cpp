class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = create(coins, 0, amount, dp);
        return (res == 1e9 ? -1 : res);
    
    }
    
private: 
    int create(vector<int>& coins, int idx, int am, vector<vector<int>>& dp) {
        
        if(idx == coins.size()) {
            return am == 0 ? 0 : 1e9;
        }
        
        if(dp[idx][am] != -1) return dp[idx][am];
        
        int take = (coins[idx] <= am ? 1 + create(coins, idx, am - coins[idx], dp) : 1e9);
        int ntake = create(coins, idx + 1, am, dp);
        
        return dp[idx][am] = min(take, ntake);
    }
};