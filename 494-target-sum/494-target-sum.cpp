class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> mem(nums.size());
        return create(nums, 0, 0, target, mem);
    }
    
private:
    int create(vector<int>& nums, int point, int sum, int target, vector<unordered_map<int, int>>& mem) {
        if(point >= nums.size()) {
            return sum == target;
        }
        
        auto it = mem[point].find(sum);
        if(it != mem[point].end()) return it -> second;        
        
        return mem[point][sum] =  create(nums, point+1, sum - nums[point], target, mem) + create(nums, point+1, sum + nums[point], target, mem);
    }
};