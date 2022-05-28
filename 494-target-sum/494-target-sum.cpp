class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> mem(nums.size());
        return create(nums, 0, 0, target, mem);
    }
    
private: 
    int create(vector<int>& nums, int idx, int sum, int target, vector<unordered_map<int, int>>& mem) {
        if(idx >= nums.size()) {
            return sum == target;
        }
        
        auto it = mem[idx].find(sum);
        if(it != mem[idx].end()) return it -> second;
        
        return mem[idx][sum] = create(nums, idx + 1, sum + nums[idx], target, mem) + create(nums, idx + 1, sum - nums[idx], target, mem);
    }
};