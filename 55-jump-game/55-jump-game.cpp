class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return create(nums, 0, dp);
    }
private:
    bool create(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx >= nums.size() -1) return true;
        if(nums[idx] == 0) return false;
        
        if(dp[idx] != -1) return dp[idx];
        int reach = idx + nums[idx];
        for(int jump=idx + 1; jump <= reach; jump++) {
            if(create(nums, jump, dp)) 
                return dp[idx] = true;
        }
        
        return dp[idx] = false;
    }
};