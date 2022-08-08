class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int idx = 0, prev_idx = -1, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return create(nums, idx, prev_idx, dp);
    }
    
private: 
    int create(vector<int>& nums, int idx, int prev_idx, vector<vector<int>>& dp) {
        if(idx == nums.size()) {
            return 0;
        }
       
        
        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx +1];
    
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            int take = 1 + create(nums, idx+1, idx, dp); 
            int ntake = create(nums, idx+1, prev_idx, dp);
            
            return dp[idx][prev_idx + 1] = max(take, ntake);
        }
        
        return dp[idx][prev_idx + 1] = create(nums, idx + 1, prev_idx, dp);
    }
};