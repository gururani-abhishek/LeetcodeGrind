class Solution {
public:
    
    // bruteforce backtracking = tc : o(2n), sc : o(n) -> stack space.
    // memoized = tc : o(n3), sc : o(n) + o(n)-> stack space & dp array ;
    //tc : o(n3), outerloop(add_idx -> worstcase o(n)), inner recursion(o(n) worstcase), findOperation(o(n));
    
    bool wordBreak(string s, vector<string>& wordDict) {
        //I need to have a map that represents wordDict in order to search if a substring that I've created
        //is a part of wordDict or not.
        
        set<string> mapWordDict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return create(s, mapWordDict, 0, dp);
        //0 represents the index, from which I'll be making my substrings.
    }
    
private: 
    bool create(string &s, set<string>& mapWordDict, int idx, vector<int>& dp) {
        if(idx == s.length()) return true;
        
        if(dp[idx] != -1) return dp[idx];
        
        string sub = "";

        for(int add_idx = idx; add_idx<s.length(); add_idx++) {
            //create substrings, by adding new letter to the previous sub-string.
            sub += s[add_idx];
            
            
            //if it's found in the map, explore further.
            //if nothing is being found in the map, just return a false when the entire string is 
            //exhausted and not substring matches. 
            
            if(mapWordDict.find(sub) != mapWordDict.end() && create(s, mapWordDict, add_idx+1, dp))  {
                
                //create function call recurrence for the further leftover part.
                //till add_idx, the subarray matched, hence I need to explore further
                //from add_idx + 1;
                return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
};


/*


case : applepenapple

ans = true;

create(idx = 0) -> return true;
(apple -> found) {
    create(find pen);  -> return true;
}    

(pen -> found) {
    create(find apple); -> return true;
}

(apple -> found) {
    create(rest of the part, that is end of the string); -> return true;
}
     
*/