class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = 0;
        sort(nums.begin(), nums.end());
        create(nums, n);
        return ans;
    }
    
private:
    void create(vector<int> nums, int n) {
        if(n == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i =n; i<nums.size(); i++) {
            if(i != n && nums[i] == nums[n]) continue;
            swap(nums[i], nums[n]);
            create(nums, n+1);
        }
    }
};

/*

1, 1, 2

0th position: 
1 1 2
1 2 1

// 1 1 2
// 1 2 1

2 1 1
// 2 1 1



*/