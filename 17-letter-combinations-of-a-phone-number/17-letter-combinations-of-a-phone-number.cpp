class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string ans1 = "";
        create(digits, 0, ans1, mp);
        return ans;
    }

private:
    void create(string digits, int point, string& ans1, unordered_map<char, string>& mp) {
        if(point == digits.length()) {
            ans.push_back(ans1);
            return;
        }
        
        for(int i=0; i<mp[digits[point]].size(); i++) {
            ans1.push_back(mp[digits[point]][i]);
            create(digits, point+1, ans1, mp);
            ans1.pop_back();
        }
    }
};