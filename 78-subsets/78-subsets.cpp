class Solution {
public:
    set<vector<int>> set;
    void fun(vector<int> element, vector<int> nums) {
        if(nums.size() == 0) {
            set.insert(element);
            return;
        }
        
        vector<int> element1 = element;
        vector<int> element2 = element;
        
        element2.push_back(nums[0]);
        nums.erase(nums.begin()+ 0);
        
        fun(element1, nums);
        fun(element2, nums);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> element;  
    
        fun(element, nums);
        
        for(auto u: set) {
            ans.push_back(u);
        }
        
        return ans;

    }
};