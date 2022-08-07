class Solution {
public:
    
    //tc 
    /*  'N' is the size of our string.
        recursive -> exponential -> O(5*4^N-1) ~ O(4^N) ~ exponential
        memoization -> O(N*200)
        tabulation ->  O(N*5) {for 5 vowels}
    */
    //sc 
    /*
        recursive -> O(N) -> stack space
        memoization -> O(N*200) + O(N) -> dp table plus stack space    
        tabulation -> O(N*200) -> dp table
    */
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        long long ans = 0;
        
        vector<vector<long long>> dp(n+1, vector<long long>(200, 0));
        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
        
        for(int i=0; i<5; i++) {
            dp[0][vowels[i]] = 1;
        }
        
        for(int idx = 1; idx < n; idx++) {
            for(auto prev: vowels) {
                long long take = 0;
        
                if(prev == 'a') {
                    take += dp[idx-1]['e'] % mod;
                } 
                if(prev == 'e') {
                    take += dp[idx-1]['a'] % mod + dp[idx-1]['i'] % mod;
                }
                if(prev == 'i') {
                    take += dp[idx-1]['a'] % mod + dp[idx-1]['e'] % mod + dp[idx-1]['o'] % mod + dp[idx-1]['u'] % mod;
                }
                if(prev == 'o') {
                    take += dp[idx-1]['i'] % mod + dp[idx-1]['u'] % mod;
                }

                if(prev == 'u') {
                    take += dp[idx-1]['a'] % mod;
                }
        
                
                dp[idx][prev] = take % mod;
            }
        }
        
        
        for(int i=0; i<5; i++) {
            ans += dp[n-1][vowels[i]] % mod;
        }
        
        return ans % mod;
    }

};