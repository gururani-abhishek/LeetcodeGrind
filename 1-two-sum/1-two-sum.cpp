class Solution {
public:
    // you have to return the indices, and not the values.
    // I need a vector of pair, to store the indices too.
    vector<int> twoSum(vector<int>& nums, int target) {
        // need to store elements and their indices in a vector pair, 
        vector<pair<int, int>> numsPlusIdx; 
        for(int idx = 0; idx < nums.size(); idx++) {
            // as I'll sort the elements on the basis of their values, 
            // the first pair is going to be the element. 
            numsPlusIdx.push_back({nums[idx], idx});
        }
        
        // a vector pair gets sorted on the basis of 1st value(i.e. elements)
        sort(numsPlusIdx.begin(), numsPlusIdx.end()); 
        
        // 1, 2, 3, 4, 5, 6
        
        vector<int> res;
        int l = 0, r = nums.size() - 1; // two pointers, left and right
        while(l < r) {
            if(numsPlusIdx[l].first + numsPlusIdx[r].first > target) {
                r--;
            } else if(numsPlusIdx[l].first + numsPlusIdx[r].first < target) {
                l++;
            } else {
                res = {numsPlusIdx[l].second, numsPlusIdx[r].second};
                break;
            }
        }
        
        return res;
    }
};