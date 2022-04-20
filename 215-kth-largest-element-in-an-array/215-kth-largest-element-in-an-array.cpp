class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = INT_MAX, h = INT_MIN;
        for(auto u: nums) {
            l = min(l, u);
            h = max(h, u);
        }
    
        while(l < h) {
            int mid = l + (h -l)/2;
            
            int c = 0;
            for(auto u: nums) c += (u <= mid);
        
            if(c >= nums.size() - k + 1) h = mid;
            else l = mid + 1;
        }
        
        return l;
    }
};


//kth largest element is basically
//size - k + 1 smallest element

//1, 2, 3, 4, 5
//2nd largest is (size - 2 + 1)