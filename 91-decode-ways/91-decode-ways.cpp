class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return create(s, 0, dp);
    }
    
private: 
    int create(string& s, int idx, vector<int>& dp) {
        if(idx == s.length()) return 1;
        if(s[idx] == '0') return 0;
    
        if(dp[idx] != -1) return dp[idx];
        int oneTake = create(s, idx + 1, dp);
        
        int twoTake = 0;
        if(idx + 1 < s.length()){
            if(s[idx]=='1') twoTake = create(s, idx + 2, dp); 
            else if(s[idx]=='2' && (s[idx+1]=='0'||s[idx+1]=='1'||s[idx+1]=='2'||s[idx+1]=='3'||s[idx+1]=='4'||s[idx+1]=='5'||s[idx+1]=='6'))
                twoTake = create(s, idx + 2, dp);
        }
        
        return dp[idx] = (oneTake + twoTake);
    }
};