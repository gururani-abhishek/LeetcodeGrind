class Solution {
public:
    //the difference between coin change and combination IV is that
    //in coin change, the order of things do not matter(i.e. permutation)
    //so for a testcase : {[1,2,3] 4} -> ans coin change will give = 4
    //ans combination IV will give = 7
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));
        
        for(int am = 0; am <= amount; am++) {
            dp[n][am] = (am == 0 ? 0 : 1e9);
        }
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int am =0; am <= amount; am++) {
                int take = (coins[idx] <= am ? 1 + dp[idx][am - coins[idx]]: 1e9);
                int ntake = dp[idx + 1][am];

                dp[idx][am] = min(take, ntake);
            }
        }
        
        int res = dp[0][amount];
        return (res == 1e9 ? -1 : res);
    
    }
};