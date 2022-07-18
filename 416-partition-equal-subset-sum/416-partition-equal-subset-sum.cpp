class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++) sum += nums[i];
        
        if(sum %2) return false;
        //now this problem is : "subset sum equals to sum/2" problem
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return create(nums, n-1, sum/2, dp);
    }
    
private: 
    bool create(vector<int>& nums, int idx, int target, vector<vector<int>>& dp)  {
        if(target == 0) return true;
        if(idx == 0) {
            return (nums[0] == target);
        }
        
        if(dp[idx][target] !=  -1) return dp[idx][target];
        
        bool leaveIt = false, takeIt = false;
        leaveIt = create(nums, idx-1, target, dp);
        
        if(nums[idx] <= target) takeIt = create(nums, idx-1, target-nums[idx], dp);
        
        return dp[idx][target] = (takeIt  || leaveIt);
    }
};