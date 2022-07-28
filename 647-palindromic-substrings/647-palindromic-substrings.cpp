class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, maxPaliLen = 0, n = s.length();

        for(int idx = 0; idx < n; idx++) {
            
            //for palin's like : aba
            int l = idx, r = idx;
            while(l >= 0 && r <= n-1 && s[l] == s[r]) {
                res++;
                l--, r++;
            }
            
            //for plain's like : abba
            l = idx, r = idx + 1;
            while(l >= 0 && r <= n-1 && s[l] == s[r]) {
                res++;
                l--, r++;
            }
        }
        
        return res;
    }
};