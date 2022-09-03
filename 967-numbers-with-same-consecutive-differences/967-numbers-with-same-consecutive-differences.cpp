class Solution {
public:
    vector<int> res; // final answer
    vector<int> numsSameConsecDiff(int n, int k) {
        int prev = -1;
        int res1 = 0; // local answer

        // recursive function to find vectors of size 'n' with consec digit diff 'k'
        create(n, k, res1, prev); 
        
        
        // return final answer
        return res;
    }
    
private : 

    void create(int n, int k, int res1, int prev) {
        // base case, when I've worked upon all the digits(i.e. when the entire number
        // if formed) ->
        if(n == 0) {
            res.push_back(res1); // push res1 to res;
            return; // return from here 
        }
        
        for(int newEl = 0; newEl <= 9; newEl++) {
            // this is the first digit and you cannot use a zero
            // ***must not have leading zeroes***
            if(prev == -1 && newEl == 0) continue; 
            
            // if abs(diff of new digit and prev is equal to k) 
            if(prev == -1 || abs(newEl - prev) == k) {
                // call recursion ->
                
                // add this digit to your number
                // res1 *= 10;
                // res1 += newEl;
                create(n-1, k, res1 * 10 + newEl, newEl); 
                
                // while backtracking revert it back 
                // res1 /= 10;
            }
            
        }
        
    }
    
};

// +ve integers of length 'n'  such that abs(difference between any two consecutive digits) 
// is 'k'

// I think this is a question of backtracking aka recursion 