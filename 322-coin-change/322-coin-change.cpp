class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        for(int am = 0; am <= amount; am++) {
            if(am % coins[0] == 0) dp[0][am] = am/coins[0];
            else dp[0][am] = 1e9;
        }
        
        for(int idx = 1; idx <n; idx++) {
            for(int am = 0; am <= amount; am++) {
                int leaveIt = dp[idx -1][am];
                int takeIt = (coins[idx] <= am) ? 1 + dp[idx][am - coins[idx]] : 1e9;
        
                dp[idx][am] = min(leaveIt, takeIt);
            }
        }
        
        int ans = dp[n-1][amount];
        return ans == 1e9 ? -1 : ans;
    }
};