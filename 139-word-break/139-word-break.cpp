class Solution {
public:
    
    // recursive -> tc : O(2^n) -> I can either divide or not(2choices) the given string into 'n' pieces, sc : O(n)
    // memoization -> tc : O(n*n*n) -> (n calls * n sized loop * n find) 
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //on every call if the first part is matched, I've to search for the rest part
        //to make search easy, I'm using a set. find tc : O(n) -> {worst case}
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return create(s, wd, 0, dp);
    }
    
private: 
    bool create(string &s, unordered_set<string> &wordDict, int idx, vector<int> &dp) {
        //if idx has reached the end, our string is already divided into space separated substrings 
        //present in wordDict
        if(idx == s.length()) return true;
        
        
        if(dp[idx] != -1) return dp[idx];
        
        //in every call I've to create a new substring starting from idx
        string sub = ""; //new call, hence a new substring to be made
        for(int i = idx; i < s.length(); i++) {
            sub += s[i];//keep on adding the string chars
            
            //check if the substring is present or not, if present carry on the same process for the leftover part
            if(wordDict.find(sub) != wordDict.end() && create(s, wordDict, i+1, dp)) 
                return dp[idx] = true;
        }
        
        
        //didn't match -> return false
        return dp[idx] = false;
    }
};