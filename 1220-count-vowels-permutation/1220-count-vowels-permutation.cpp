class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        long long ans = 0;
        
        vector<vector<int>> dp(n, vector<int>(200, -1));
        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for(int i=0; i<5; i++) {
            ans += create(n-1, vowels[i], dp) % mod;
        }
        
        return ans % mod;
    }

private: 
    long long create(int n, char prev, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        
        
        if(dp[n][prev] != -1) return dp[n][prev];
        long long take = 0;
        
        if(prev == 'a') {
            take += create(n-1, 'e', dp) % mod;
        } 
        if(prev == 'e') {
            take += create(n-1, 'a', dp) % mod + create(n-1, 'i', dp) % mod;
        }
        if(prev == 'i') {
            take += create(n-1, 'a', dp) % mod + create(n-1, 'e', dp) % mod + create(n-1, 'o', dp) % mod + create(n-1, 'u', dp) % mod;
        }
        if(prev == 'o') {
            take += create(n-1, 'i', dp) % mod + create(n-1, 'u', dp) % mod;
        }
        
        if(prev == 'u') {
            take += create(n-1, 'a', dp) % mod;
        }
        
        return dp[n][prev] = take % mod;
    }
};