class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> element;
        sort(nums.begin(), nums.end());
        
        create(element, nums);
        return ans;
    }
private: 
    void create(vector<int> element, vector<int> nums) {
        if(nums.size() == 0) {
            ans.push_back(element);
            return;
        }
        
        int x = nums[0];
        element.push_back(x);
        nums.erase(nums.begin() + 0);
        
        create(element, nums);  //taken
        element.pop_back();
        int i;
        for(i=0; i<nums.size() && nums[i] == x; i++);
        nums.erase(nums.begin(), nums.begin() + i);
        
        create(element,nums);
    }
};