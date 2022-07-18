class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++) sum += nums[i];
        
        if(sum %2) return false;
        //now this problem is : "subset sum equals to sum/2" problem
        vector<bool> prev(sum/2 + 1, false);
        vector<bool> curr(sum/2 + 1, false);
        
        //define basecases: 
        //1st bC: doesn't matter what idx is, if target == 0, return true;
        for(int idx=0; idx<n; idx++) prev[0] = true;
        
        //2nd bC: when idx is equal to 0 and target == nums[0], return true;
        if(nums[0] <= sum/2 + 1) prev[nums[0]] = true;
        
        for(int idx=1; idx<n; idx++) {
            for(int target = 1; target <= sum/2; target++) {
            bool leaveIt = false, takeIt = false;
            leaveIt = prev[target]; 
        
            if(nums[idx] <= target) takeIt = prev[target-nums[idx]];
        
            curr[target] = (takeIt  || leaveIt);
            }
            prev = curr;
        }
        
        return prev[sum/2];
    }
};