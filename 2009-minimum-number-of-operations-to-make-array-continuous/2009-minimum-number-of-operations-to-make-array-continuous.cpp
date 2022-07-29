class Solution {
public:
    
    //tc : o(nlogn); sc : o(n);
    //the test cases here are deceptive, none of them cover the case where, nums will have repeating elements.
    int minOperations(vector<int>& nums) {
        //as nums should have unique values, all non-unique values should be 
        //removed. Infact non-unique ones will be have to be replaced, costing one operation
        //so it's fine to remove all of them.
        int n = nums.size(); 
        
        set<int> container; //container To Remove Repeating Elements Plus To Sort the Left Ones
        
        for(int idx = 0; idx < nums.size(); idx++) container.insert(nums[idx]);
        nums.clear();
        for(auto u: container) nums.push_back(u);
        //nums now contain only unique values and that too in sorted fashion.
        
        //the sole idea behind a continuous array  is that it should be continuous from the start element till the end element
        //we'll take each element as the start element and then we'll check how many elements are missing from the 
        //array if it was continuous, we'll choose the element for which max number of elements will be present for our 
        //array to be continuous, in other words we'll choose the element for which minimum no. of chages would be required
        
        int minOp = INT_MAX;
        for(int idx=0; idx<n; idx++) {
            int start = nums[idx];
            int end = start + n - 1; //from : (end - start = n - 1), difference between max and min should be equal to size - 1;
            
            //BS to find element just greater than end element, so the difference will give the no. of elements between start & end.
            auto itToEnd = upper_bound(nums.begin(), nums.end(), end);
            int end_idx = itToEnd - nums.begin();
            
            int eleBetween = end_idx - idx; //no. of elements between end & start
            int nOfMissingElements = n - eleBetween; //no. of elements required to make nums continuous.
            
            minOp = min(minOp, nOfMissingElements);
        }
        
        
        return minOp;
    }
};


//initial mistake, n should be the size of original nums as that size can only tell us how much elements are required exactly.