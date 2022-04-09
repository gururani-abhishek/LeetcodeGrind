class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string op = "";
        create(op, 2*n);
        return ans;
    }
    
private: 
    void create(string op, int count) {
    
        if(count == 0) {
            if(check(op)) ans.push_back(op);
            return;
        }
        
        string op1 = op;
        op1.push_back('(');
        op.push_back(')');
        count--;
        create(op, count);
        create(op1, count);        
    
    }
    
    bool check(string s) {
        int count = 0;
        for(int i =0; i<s.length(); i++) {
            count += (s[i] == '(');
            count -= (s[i] == ')');
            
            if(count < 0) return false;
        }
        return count == 0? true : false;
        
    }
};