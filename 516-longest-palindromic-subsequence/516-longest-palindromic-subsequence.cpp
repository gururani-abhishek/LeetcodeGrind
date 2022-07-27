class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return create(s, revs, 0, 0, dp); 
    }

private: 
    int create(string &s, string &revs, int idxs, int idxrevs, vector<vector<int>>& dp) {
        if(idxs >= s.length() || idxrevs >= revs.length()) return 0;
        
        if(dp[idxs][idxrevs] != -1) return dp[idxs][idxrevs];
        //they match 
        if(s[idxs] == revs[idxrevs]) return 1 + create(s, revs, idxs+1, idxrevs+1, dp);
        
        //they do not match;
        return dp[idxs][idxrevs] = max(create(s, revs, idxs+1, idxrevs, dp), create(s, revs, idxs, idxrevs + 1, dp));
    }
};