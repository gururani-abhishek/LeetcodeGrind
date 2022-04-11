class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string op = "";
        create(op, n, n);
        return ans;
    }
private: 
    void create(string op, int open, int closed) {
        if(open == 0 && closed ==0) {
            ans.push_back(op);
            return;
        }
        
        if(open > 0) {
            string op1 = op;
            op1.push_back('(');
            create(op1, open -1, closed);
        }
        
        if(open < closed) {
            op.push_back(')');
            create(op, open, closed - 1);
        }
    }
};