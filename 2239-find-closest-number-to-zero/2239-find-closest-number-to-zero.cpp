class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mn = INT_MAX, ans;
        sort(nums.begin(), nums.end());
        for(auto u: nums) {
           if(mn >= abs(u)) {
               mn = abs(u);
               ans = u;
           } 
        }
        
        return ans;
    }
};