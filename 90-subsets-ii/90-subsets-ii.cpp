class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();
        
        for(int i=0; i<(1<<n); i++) {
            vector<int> element;
            for(int j =0; j<n; j++) {
                if(i & (1<<j)) element.push_back(nums[j]);        
            }
            sort(element.begin(), element.end());
            s.insert(element);
        }
                
        vector<vector<int>> ans; 
        for(auto u: s)
            ans.push_back(u);
        
        return ans;
    }
};