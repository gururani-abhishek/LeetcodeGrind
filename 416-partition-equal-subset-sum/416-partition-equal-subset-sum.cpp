class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
        return create(nums, 0, 0, sum, dp);
    }
    
private: 
    bool create(vector<int>& nums, int idx, int sum1, int sum, vector<vector<int>>& dp) {
        if(sum1 == sum) return true;
        if(idx > nums.size()-1) return false;
        
        if(dp[idx][sum1] != -1) return dp[idx][sum1];
        int takeIt = false, leaveIt = false;
        leaveIt = create(nums, idx+1, sum1, sum, dp);
        
        if(sum1 + nums[idx] <= sum) takeIt = create(nums, idx+1, sum1+nums[idx], sum -nums[idx], dp);
        
        return dp[idx][sum1] = (takeIt || leaveIt);
    }
};