class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> ans1;
        create(s, ans1, 0);
        return ans;
    }
    
private:
    void create(string s, vector<string>& ans1, int point) {
        if(point == s.size()) {
            ans.push_back(ans1);
            return;
        }
        
        string str = "";
        for(int i =point; i<s.size(); i++) {
            str.push_back(s[i]);
            if(!checkPalindrome(str)) continue;
            
            ans1.push_back(str);
            create(s, ans1, i+ 1);
            ans1.pop_back();
        }
        
    }
    
    bool checkPalindrome(string s) {
        int i = 0, j = s.size() -1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        
        return true;
    }
};