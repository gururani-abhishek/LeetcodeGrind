class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size()-1;
        
        while(lo < hi) {
            if(numbers[lo] + numbers[hi] == target) {
                return vector<int> ({lo+1, hi+1});
            } else if(numbers[lo] + numbers[hi] < target) {
                lo++;
            } else hi--;
        }
        
        return {};
    }
};