class Solution {
public:
    int rob(vector<int>& nums) {
        int oneBefore = nums[0], twoBefore;
        int n = nums.size();
        for(int i=1; i<n; i++) {
            
            int robIt = nums[i];
            if(i-2 >= 0) robIt += twoBefore;
            int notRobIt = oneBefore;
            
            twoBefore = oneBefore;
            oneBefore = max(robIt, notRobIt);
        }
        
        return oneBefore;
    }

};