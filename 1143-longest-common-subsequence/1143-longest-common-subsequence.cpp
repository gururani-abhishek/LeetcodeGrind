class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        //basecases: 
        for(int idx2 = 0; idx2 <= m; idx2++) dp[0][idx2] = 0;
        for(int idx1 = 0; idx1 <= n; idx1++) dp[idx1][0] = 0;
        
        for(int idx1 = 1; idx1 <= n; idx1++) {
            for(int idx2 = 1; idx2 <=m; idx2++) {
                if(text1[idx1 -1] == text2[idx2-1]) {
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                    continue;
                }
                
                dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);        
            }
        }
        
        return dp[n][m];        
    }
};