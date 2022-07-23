class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return create(0, -1, nums, dp);
    }
    
private: 
    int create(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& dp) {
       
        if(idx == nums.size() -1) {
            if(prev_idx == -1 || nums[idx] > nums[prev_idx]) return 1;
            return 0;
        }
        
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx + 1];
        int take = 0, nottake = create(idx+1, prev_idx, nums, dp);
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]) take = 1 + create(idx +1, idx, nums, dp);
        
        return dp[idx][prev_idx+1] = max(take, nottake);
        
    }
};