class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapValIdx;  // mapping val with it's idx
        
        vector<int> res; // will store the result
        
        // when we use a hash map, our focus should be on searching for it's elements : 
        for(int idx = 0; idx < nums.size(); idx++) {
            
            int otherElement = target - nums[idx]; // now I'll search for this otherElement
        
            // map.begin()         map.end()
            // [-] [-] [-] [-] [-] 
            
            
            if(mapValIdx.find(otherElement) != mapValIdx.end()) {
                // other element exists, I found pairs that make up target : 
                res = {idx, mapValIdx[otherElement]};
                break;
            }
            
            // map them, val ---> idx, for further checks : 
            mapValIdx[nums[idx]] = idx;
        }
    
        return res;
    }
};

// I need to find two elements whose sum equals target
// suppose one of those two element is 'x', then the other element will be : 'target - x'
// after this observation, this question boils down to finding 'target-x' 
// for every single element of the array, and when found then return their indices.