class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tSum = 0;
        for(int i=0; i<nums.size(); i++) tSum += nums[i];
        
        if(tSum % 2 != 0 || nums.size() == 1) return false;
        
        //now I've got array whose total sum equals and even number
        //and size of the given array is 2 or greater.
        
        //6 -> 3, 3 || 8 -> 4, 4 || 36 -> 18, 18
        
        //find a subset from the given array whose sum equals : tSum/2;
        
        //1, 5, 11, 5 -> tsum = 22 -> find a subset that sums up to 11
        vector<vector<int>> dp(nums.size(), vector<int>(tSum/2 + 1, -1));
        return create(nums, 0, tSum/2, dp);
    }

private: 
    bool create(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
        if(idx == nums.size()) return target == 0 ? 1 : 0;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int takeIt = (nums[idx] <= target ? create(nums, idx + 1, target - nums[idx], dp) : 0);
        int notTakeIt = create(nums, idx + 1, target, dp);
                      
        return dp[idx][target] = (takeIt || notTakeIt);
    }
    
};