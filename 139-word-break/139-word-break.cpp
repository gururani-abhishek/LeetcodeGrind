class Solution {
public:
    
    // bruteforce backtracking = tc : o(2n), sc : o(n) -> stack space.
    // memoized = tc : o(n3), sc : o(n) + o(n)-> stack space & dp array ;
    //tc : o(n3), outerloop(add_idx -> worstcase o(n)), inner recursion(o(n) worstcase), findOperation(o(n));
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> mapWordDict(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        vector<int> dp(n+1, 0);
        
        dp[n] = 1;
        
        for(int idx = n-1; idx >=0; idx--) {
             string sub = "";

            for(int add_idx = idx; add_idx < n; add_idx++) {
                sub += s[add_idx];
                if(mapWordDict.find(sub) != mapWordDict.end() && dp[add_idx+1])  {
                dp[idx] = true;
                break;
                }
            }
        }
        
        
        
        return dp[0];
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