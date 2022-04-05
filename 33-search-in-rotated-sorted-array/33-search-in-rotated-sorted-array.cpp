class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        
        while(left < right) {
            int mid = left + (right -left)/2;
            
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        
        int indOfSmallestElement = left;
        
        left = 0, right = nums.size() -1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int trueMid = (indOfSmallestElement +mid) % nums.size();
            //trueMid is hypothetical it doesn't exist. 
            if(nums[trueMid] > target) right = mid-1;
            else if(nums[trueMid] < target) left = mid + 1;
            else return trueMid;
        }
        
        return -1;
    }
};