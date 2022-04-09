class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        string op = "";
        create(op, s);
        
        return ans;
    }
private:
    
    void create(string op, string ip) {
        if(ip.length() == 0) {
            ans.push_back(op);
            return;
        }
    //isalpha(): returns 0 if not an alphabet, else non zero
    //tolower(): to lowercase
    //toupper(): to uppercase

        string op1 = op;
        char x = ip[0];
        
        op.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        create(op, ip);
        
        if(isalpha(x)) {
            x ^= (1<<5); //toggles, lower to upper and upper to lower.
            op1.push_back(x);
            create(op1, ip);
        }
        
    }
};