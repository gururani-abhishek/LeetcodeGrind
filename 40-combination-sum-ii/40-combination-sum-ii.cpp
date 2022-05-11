class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans1;
        sort(candidates.begin(), candidates.end());
        create(candidates, target, 0, 0, ans1);
        return ans;
    }
private:
    void create(vector<int>& candidates, int target, int point, int sum, vector<int>& ans1) {
        if(sum == target || point == candidates.size()) {
            if(sum == target) ans.push_back(ans1);
            
            return;
        }
        
        for(int i=point; i<candidates.size(); i++) {
            if(i > point && candidates[i] == candidates[i-1]) continue;
            if(sum + candidates[i] > target) continue;
            ans1.push_back(candidates[i]);
            create(candidates, target, i+1, sum+candidates[i], ans1);
            ans1.pop_back();
        }
    }
};

