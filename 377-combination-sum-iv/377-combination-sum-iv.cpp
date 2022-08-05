class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return create(nums, target, dp);
    }
    
private:
    int create(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) return 1;
        
        if(dp[target] != -1) return dp[target];
        int res = 0;
        for(auto integer : nums) {
            res += (integer <= target ? create(nums, target - integer, dp) : 0);
        }
        
        return dp[target] = res;
    }
};