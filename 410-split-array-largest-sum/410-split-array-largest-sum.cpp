class Solution {
public:
    
    int splitArray(vector<int>& nums, int m) {
        int l =-1e9, h =0;
        for(auto u: nums) {
            h += u;
            l = max(l, u);
        }
        
        while(l < h) {
            int mid = l + (h - l)/2;
            if(countSubarrays(nums, mid) <= m) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        
        
        return l;
    }

private: 
    int countSubarrays(vector<int> nums, int maxS) {
        int total = 0, subarrays = 1;
        
        
        for(int i=0; i<nums.size(); i++) {
            if(total + nums[i] <= maxS) total += nums[i];
            else {
                total = nums[i];
                subarrays++;
            }
        }
        
        return subarrays;
    }
};