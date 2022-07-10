class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return findMaxRobbery(nums, nums.size() -1, dp);
    }

private: 
    int findMaxRobbery(vector<int>& nums, int n, vector<int>& dp) {
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        int robIt = nums[n] + findMaxRobbery(nums, n-2, dp); 
        int notRobIt = findMaxRobbery(nums, n-1, dp);
        
        return dp[n] = max(robIt, notRobIt);
    }
};