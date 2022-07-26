class Solution {
public:
    
    vector<vector<int>> dpM;
    vector<int> dpm;
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        dpM.resize(n, vector<int>(2, -1));
        dpm.resize(n, -1);
        
        bool hasPicked = false;
        return createM(nums, hasPicked, 0);
    }

private: 
    long createM(vector<int>& nums, bool hasPicked, int idx) {
        if(idx == nums.size()) {
            return (hasPicked ? 1 : INT_MIN);
        }
        
        if(dpM[idx][hasPicked] != -1) return dpM[idx][hasPicked];
        if(hasPicked) {
            long pickit = nums[idx] * (nums[idx] >= 0 ? createM(nums, true, idx + 1) : createm(nums, idx + 1));
            return dpM[idx][hasPicked] = max(1l, pickit);
        }
        
        long pickit = nums[idx] * (nums[idx] >= 0 ? createM(nums, true, idx +1) : createm(nums, idx + 1));
        long npickit = createM(nums, false, idx + 1);
        
        return dpM[idx][hasPicked] = max(pickit, npickit);
        
        
    }
    
    long createm(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            return 1;
        }
        if(dpm[idx] != -1) return dpm[idx];
        return dpm[idx] = nums[idx] * (nums[idx] >= 0 ? createm(nums, idx + 1) : createM(nums, true,  idx + 1));
    }
};