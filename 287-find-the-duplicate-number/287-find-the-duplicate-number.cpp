class Solution {
public:
    int countLesserElements(vector<int> nums, int element) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) count += (nums[i] <= element);
        
        return count;
    }
    
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() -1;
        
        while(l < r) {
            int mid = l + (r -l)/2;
            
            if(countLesserElements(nums, mid) > mid) r = mid; 
            else l = mid + 1;
        }
        
        return l;
    }
};