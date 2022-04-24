class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        string s1 = "";
        create(s1, s);
        return ans;
    }
    
private:
    void create(string s1, string s)  {
        if(s.size() == 0) {
           ans.push_back(s1);
           return;
        }
        
        char x= s[0];
        s.erase(s.begin() + 0);
        
        if(isalpha(x)) {
            string s2 = s1;
            s1.push_back(toupper(x));
            s2.push_back(tolower(x));
            create(s1, s);
            create(s2, s);
        
        }else {
            s1.push_back(x);
            create(s1, s);    
        }
    }
};