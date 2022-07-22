class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return create(coins, amount, n-1, dp);
    }
    
private: 
    int create(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {
        if(idx == 0) {
            return (amount % coins[0] == 0);
        }   
        
        
        // 1, 2...
        // 2, 2...
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int takeIt = (coins[idx] <= amount) ? create(coins, amount - coins[idx], idx, dp) : 0;
        int leaveIt = create(coins, amount, idx-1, dp);
        
        return dp[idx][amount] = (takeIt + leaveIt);
    }
};