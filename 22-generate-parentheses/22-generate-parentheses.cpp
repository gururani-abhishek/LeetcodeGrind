class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        string op = "";
        create(op, open, close);
        
        return ans;
    }
    
private: 
    void create(string op, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }
        
        if(open > 0) {
            string op1 = op;
            op1.push_back('(');
            create(op1, open-1, close);
        } 
        
        if(open < close) {
            string op2 = op;
            op2.push_back(')');
            create(op2, open, close -1);
        }
        
    }
};