class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans1;
        create(k, n, 0, 1, ans1);
        
        return ans;
    }
    
private: 
    void create(int k, int target, int sum, int point, vector<int>& ans1) {
        if(ans1.size() == k) {
            if(sum == target) {
                ans.push_back(ans1);
            }
        
            return;
        }
        
        for(int i=point; i<=9; i++) {
            if(i + sum > target) return;
            ans1.push_back(i);
            create(k, target, sum+i, i+1, ans1);
            ans1.pop_back();
        }
    }
};