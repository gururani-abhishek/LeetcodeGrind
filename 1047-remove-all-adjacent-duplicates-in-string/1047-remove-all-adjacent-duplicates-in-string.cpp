class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> stk; // stack
        
        for(int idx = s.size() -1; idx >= 0; idx--) {
            
            char u = s[idx]; 
            
            if(stk.empty()) {
                stk.push(u);                
            } else if(stk.top() == u) {
                stk.pop(); 
            } else {
                stk.push(u); 
            }
        }
        
        string res = ""; 
        while(!stk.empty()) {
            res += stk.top(); 
            stk.pop(); 
        }
        
        return res; 
    }
};
