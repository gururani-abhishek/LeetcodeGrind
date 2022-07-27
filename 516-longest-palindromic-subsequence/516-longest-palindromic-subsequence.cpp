class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        
        for(int idxs=0; idxs<=s.size(); idxs++) dp[idxs][s.size()] = 0;
        for(int idxrevs=0; idxrevs<=s.size(); idxrevs++) dp[s.size()][idxrevs] = 0;
        
        for(int idxs = s.size()-1; idxs >= 0; idxs--) {
            for(int idxrevs = s.size()-1; idxrevs >= 0; idxrevs--) {
                if(s[idxs] == revs[idxrevs]) {
                    dp[idxs][idxrevs] = 1 + dp[idxs+1][idxrevs+1];
                    continue;        
                }
                
            //they do not match;
            dp[idxs][idxrevs] = max(dp[idxs+1][idxrevs], dp[idxs][idxrevs + 1]);

            }
        }
        
        return dp[0][0];
        
    }

};