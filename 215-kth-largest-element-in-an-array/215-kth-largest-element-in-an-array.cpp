class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());
        
        while(l < h) {
            int mid = l + (h-l)/2;
            
            if(countGreaterThanOrEqual(nums, mid) < nums.size()-k+1) l = mid + 1;
            else h = mid;
        }
        
        return l;
    }

private: 
    int countGreaterThanOrEqual(vector<int>& nums, int key) {
        int count = 0;
        for(auto u: nums) 
            count += (u <= key);
    
        return count;
    }
};