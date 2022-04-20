class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = INT_MAX, h = INT_MIN;
        for(auto u: nums) {
            l = min(l, u);
            h = max(h, u);
        }
        
        while(l < h) {
            int mid = l + (h-l)/2;
            
            if(countGreaterAndEqual(nums, mid) < k) h = mid;
            else l = mid + 1;
        }
        
        return l;
    }
    
private:
    int countGreaterAndEqual(vector<int>& nums, int key) {
        int c = 0;
        for(auto u: nums) c += (u > key);
        return c;
    }
};