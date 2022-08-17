class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int idx1 = INT_MAX; //step 1 element
        
        for(int idx=0; idx<n-1; idx++) {
           if(nums[idx] < nums[idx + 1]) {
               idx1 = idx;
           }
        } 
        
        //if the vector is last dict perm(i.e. descending order sorted) then you have to return 
        //vector sorted in ascending order, or reverse of the given vector
        if(idx1 == INT_MAX) {
            reverseSeg(nums, 0);
            return;
        }
        
        int idx2; //step 2 element
        for(int idx = n-1; idx > idx1; idx--) {
            if(nums[idx] > nums[idx1]) {
                idx2 = idx;
                break;
            }
        }
        
        swap(nums[idx1], nums[idx2]); //swap step1 and step2 elements
        
        //reverse segement that's to the right of idx1
        reverseSeg(nums, idx1 + 1);        
        
    }
    
private: 
    
    void reverseSeg(vector<int> &nums, int idx1) {
        int lo = idx1, hi = nums.size() -1;
        
        while(lo < hi) {
            swap(nums[lo], nums[hi]);
            lo++, hi--;
        }
    }
};