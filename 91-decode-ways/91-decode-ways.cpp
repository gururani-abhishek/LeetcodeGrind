class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int idx = n-1; idx >= 0; idx--) {
            if(s[idx] == '0') {
                dp[idx] = 0;
                continue;
            }
            
            int oneTake = dp[idx + 1];
        
            int twoTake = 0;
            if(idx + 1 < s.length()){
                if(s[idx]=='1') twoTake = dp[idx + 2]; 
                else if(s[idx]=='2' && (s[idx+1]=='0'||s[idx+1]=='1'||s[idx+1]=='2'||s[idx+1]=='3'||s[idx+1]=='4'||s[idx+1]=='5'||s[idx+1]=='6'))
                    twoTake = dp[idx + 2];
            }

            dp[idx] = (oneTake + twoTake);
        }
        
        
        return dp[0];
    }
};