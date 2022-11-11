class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        
        int res = unique.size(); // no. of unique characters, 
        auto itr = unique.begin(); 
        for(int idx = 0; idx < res; idx++, itr++) {
            nums[idx] = *itr; 
        }
        
        return res; 
        
    }
};