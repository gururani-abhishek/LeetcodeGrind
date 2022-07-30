class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //instead of passing huge prev number, using which it'll be hard to memoize the solution
        //i'm passing, the idx of previous number.
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return create(nums, 0, -1, dp);
    }
    
private: 
    int create(vector<int>& nums, int idx, int prev_idx, vector<vector<int>>& dp) {
        if(idx == nums.size()-1) {
            if(prev_idx == -1 || nums[idx] > nums[prev_idx]) return 1;
            return 0;
        }
        
        if(prev_idx != -1 && dp[idx][prev_idx] != -1) return dp[idx][prev_idx];
        
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            int takeIt = 1 + create(nums, idx +1, idx, dp);
            int notPickIt = create(nums, idx +1, prev_idx, dp);
            int mx = max(takeIt, notPickIt);
            if(prev_idx != -1) dp[idx][prev_idx] = mx;
            return mx;
        }
        

        return dp[idx][prev_idx] = create(nums, idx +1, prev_idx, dp);
    }
};