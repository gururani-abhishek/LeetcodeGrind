class Solution {
public:
    string makeGood(string s) {
        
        stack<char> stk; // at any moment it holds good string till that index
        
        // traverse the string, 
        for(int idx = s.length() -1; idx >= 0; idx--) {
            
            char alpha = s[idx]; 
            
            if(stk.empty()) {
                stk.push(alpha); // push this element in
            } else if(abs(stk.top() - alpha) == 32) {
                // it means we have two non-good values, 
                // didn't add alpha, and removed the top value, 
                stk.pop(); 
            } else {
                stk.push(alpha); 
            }
            
        }
        
        string res = ""; // result string(good string)
        // store the stk element in res string,
        while(!stk.empty()) {
            res += stk.top(); 
            stk.pop(); 
        }
        
        return res; 
    }
};

// any two adjacent characters shouldn't be same lower and upper case alphabets
// if they are then remove both of them(that's the way of removal)
// in the end return a string where no two adjacent characters are 
// same lower and upper case alphabets
