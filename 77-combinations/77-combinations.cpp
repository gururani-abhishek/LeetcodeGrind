class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans1;
        int nums = n;
        create(nums, 1, k, ans1);
        return ans;
    }

private:
    void create(int nums, int i, int k, vector<int>& ans1) {
       if(!k) {
           ans.push_back(ans1);
           return;
        }
        
        for(int j = i; j<=nums; j++) {
            ans1.push_back(j);
            create(nums, j + 1, k-1, ans1);
            ans1.pop_back();
        }
        
    }
};