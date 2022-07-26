class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool hasPicked = false; //I've picked nothing yet.
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); //dp[idx][hasPicked];
        return create(nums, hasPicked, 0, dp);
    }
    
private: 
    int create(vector<int>& nums, int hasPicked, int idx, vector<vector<int>>& dp) {
        if(idx >= nums.size()) {
            return (hasPicked? 0 : -1e9);
        }
        
        if(dp[idx][hasPicked] != -1) return dp[idx][hasPicked];
        if(hasPicked) {
            //now you'll have to pick, in order to keep the subarray contiguous
            int pickIt = nums[idx] + create(nums, true, idx+1, dp);
            return dp[idx][hasPicked] = max(pickIt, 0);
            
            //0 because after picking, the sum can be get smaller too, due to -ve numbers.
        }
        
        //nothing has yet been picked, so you can both either pick or not pick an element.
        int pickIt = nums[idx] + create(nums, true, idx + 1, dp);
        int nPickIt = create(nums, false, idx + 1, dp);
        
        return dp[idx][hasPicked] = max(pickIt, nPickIt);
    }
};