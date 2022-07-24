class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        create(nums, n-2, dp, 0);
        create(nums, n-1, dp, 1);
        
        return max(dp[0][0], dp[1][1]);
    }

private: 
    void create(vector<int>& nums, int size, vector<vector<int>>& dp, int forDp) {
        
        dp[size][forDp] = nums[size];
        
        for(int idx = size-1; idx >= 0; idx--) {
        int npick = dp[idx +1][forDp];
        int pick = nums[idx] + ((idx + 2 <= size) ? dp[idx + 2][forDp] : 0);
        
        
        dp[idx][forDp] = max(pick, npick);
        }
    }

};