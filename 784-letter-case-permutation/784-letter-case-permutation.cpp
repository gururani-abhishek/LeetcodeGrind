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
        
        bool lc = 0, uc = 0;
        lc = (ip[0] >= 'a' && ip[0] <= 'z');
        uc = (ip[0] >= 'A' && ip[0] <= 'Z');
        
        if(lc) {
            string op1 = op;
            op1.push_back(ip[0] - 32);
            op.push_back(ip[0]);
            ip.erase(ip.begin() + 0);
            create(op, ip);
            create(op1, ip);
        } else if(uc) {
            string op1 = op;
            op1.push_back(ip[0] + 32);
            op.push_back(ip[0]);
            ip.erase(ip.begin() + 0);
            create(op, ip);
            create(op1, ip);
        } else {
            op.push_back(ip[0]);
            ip.erase(ip.begin() + 0);
            create(op, ip);
        }
}
};