class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++) sum += nums[i];
        
        if(sum %2) return false;
        //now this problem is : "subset sum equals to sum/2" problem
        vector<vector<bool>> dp(n, vector<bool>(sum/2+1, 0));
        
        //define basecases: 
        //1st bC: doesn't matter what idx is, if target == 0, return true;
        for(int idx=0; idx<n; idx++) dp[idx][0] = true;
        
        //2nd bC: when idx is equal to 0 and target == nums[0], return true;
        if(nums[0] <= sum/2 + 1) dp[0][nums[0]] = true;
        
        for(int idx=1; idx<n; idx++) {
            for(int target = 1; target <= sum/2; target++) {
            bool leaveIt = false, takeIt = false;
            leaveIt = dp[idx-1][target]; 
        
            if(nums[idx] <= target) takeIt = dp[idx-1][target-nums[idx]];
        
            dp[idx][target] = (takeIt  || leaveIt);
            }
        }
        
        return dp[n-1][sum/2];
    }
};