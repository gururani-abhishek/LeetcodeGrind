class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = 0;
        create(nums,n);
        
        vector<vector<int>> fans;
        for(auto u: ans) fans.push_back(u);
        return fans;
    }
    
private:
    void create(vector<int>& nums, int n) {
        if(n == nums.size()) {
            ans.insert(nums);
            return;
        }
        
        for(int i =n; i<nums.size(); i++) {
            swap(nums[i], nums[n]);
            create(nums, n+1);
            swap(nums[i], nums[n]);
        }
    }
};

