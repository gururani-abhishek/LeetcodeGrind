class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s = "";
        create(s, n, n);
        return ans;
    }
    
private:
    void create(string s, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        
        
        if(open) {
            s.push_back('(');
            create(s, open -1, close);
            s.pop_back();
        }
        
        if(open < close) {
            s.push_back(')');
            create(s, open, close -1);
        }
    }
};