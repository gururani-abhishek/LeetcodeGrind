class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int nn = 0;
        create(nums, nn);
        return ans;
    }
    
private:
    void create(vector<int>& nums, int n) {
        if(n == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        //swap
        for(int i=n; i<nums.size(); i++) {
            swap(nums[n], nums[i]);
            create(nums, n+1);
            swap(nums[n], nums[i]);
        }
        
    }
};

/*
1 2 3, n = 0 
1, 2, 3
2, 1, 3
3, 2, 1 

1, 2, 3
1, 3, 2

2, 1, 3
2, 3, 1

3, 2, 1
3, 1, 2



*/