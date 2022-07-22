class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return create(text1, text2, n, m, dp);
    }
    
private: 
    int create(string&s1, string&s2, int idx1, int idx2, vector<vector<int>>& dp) {
        if(idx1 == 0 || idx2 == 0) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1 -1] == s2[idx2-1]) return 1 + create(s1, s2, idx1-1, idx2-1, dp);
        
        return dp[idx1][idx2] = max(create(s1, s2, idx1-1, idx2, dp), create(s1, s2, idx1, idx2-1, dp));
    }
};