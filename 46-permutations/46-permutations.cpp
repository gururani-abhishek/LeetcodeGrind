class Solution {
public:
    /*
    time complexity: O(n! * n), n! unique permutations & looping through nums(size: n)
    space complexity: except the ans, I'm taking a vector: O(n) plus an array: O(n)
    auxiliary space: O(n) for n recursive calls 
    */
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int map[nums.size()];
        for(int i=0; i<nums.size(); i++) map[i] = 0;                                            
        vector<int> ans1;   
        create(nums, ans1, map);
        return ans;
    }
private:
    
    void create(vector<int>& nums, vector<int>& ans1, int map[]) {
        if(ans1.size() == nums.size()) {
            ans.push_back(ans1);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(!map[i]) {
                ans1.push_back(nums[i]);
                map[i] = 1;
                create(nums, ans1, map);
                map[i] = 0;
                ans1.pop_back();
            }
        }
            
    }
};

//mistake
// map ->  array -> 0 -> mapped
// map -> key -> value