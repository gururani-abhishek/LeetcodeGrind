class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for(auto u: nums) sum += u;
        
        if(sum % k != 0) return false;
        vector<int> visited(nums.size(), 0);
        return create(nums, visited, 0, 0, sum/k, k);
    }
    
private:
    bool create(vector<int>& nums, vector<int>& visited, int idx, int sum, int target, int k) {
        if(k == 1) return 1; //if k is 4 and 3 subsets are already found, fourth is already found.
        if(idx == nums.size()) return false;
        
            if(sum == target) {
                return create(nums, visited, 0, 0, target, k-1);
            }
    
        if(!visited[idx] && nums[idx] + sum <= target) {
            visited[idx] = 1;
            if(create(nums, visited, idx+1, sum + nums[idx], target, k)) return true;
            visited[idx] = 0;
        }
        
        return create(nums, visited, idx +1, sum, target, k);
        
    }
};