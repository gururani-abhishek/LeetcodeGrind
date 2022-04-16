class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mn = INT_MAX, ans;
        for(auto u: nums) {
           if(mn > abs(u)) {
               mn = abs(u);
               ans = u;
           } else if(mn == abs(u)) {
               ans = max(ans, u);
           }
        }
        
        return ans;
    }
};