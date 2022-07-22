class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = create(coins, n-1, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
    
private: 
    int create(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
        if(idx == 0) {
            if(amount % coins[0] == 0) return (amount/coins[0]);
            return 1e9;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int leaveIt = create(coins, idx -1, amount, dp);
        int takeIt = (coins[idx] <= amount) ? 1 + create(coins, idx, amount - coins[idx], dp) : 1e9;
        
        return dp[idx][amount] = min(leaveIt, takeIt);
    }
};