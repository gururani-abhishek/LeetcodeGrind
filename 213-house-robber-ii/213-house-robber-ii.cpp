class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int start_with_zeroIdx = create(0, nums, n-2, dp, 0);
        int start_with_oneIdx = create(1, nums, n-1, dp, 1);
        
        return max(start_with_oneIdx, start_with_zeroIdx);
    }

private: 
    int create(int idx, vector<int>& nums, int size, vector<vector<int>>& dp, int forDp) {
        if(idx == size) {
            return nums[idx];
        }
        
        if(dp[idx][forDp] != -1) return dp[idx][forDp];
        int npick = create(idx +1, nums, size, dp, forDp);
        int pick = nums[idx] + ((idx + 2 <= size) ? create(idx + 2, nums, size, dp, forDp) : 0);
        
        
        return dp[idx][forDp] = max(pick, npick);
    }

};