class Solution {
public:
    string longestPalindrome(string s) {
        int ansS, ansE, mxLenPali = 0, n =s.length();

        for(int idx = 0; idx < n; idx++) {
            //for string like : aba
            int l = idx, r = idx;
            while(l >= 0 && r <= n-1 && s[l] == s[r]) {
                if(r - l + 1 > mxLenPali) {
                    mxLenPali = r - l + 1;
                    ansS = l;
                    ansE = r;
                }
                l--, r++;
            }
            
            
            //for string like : abba
            l = idx, r = idx + 1;
            while(l >= 0 && r <= n-1 && s[l] == s[r]) {
                if(r - l + 1 > mxLenPali) {
                    mxLenPali = r - l + 1;
                    ansS = l;
                    ansE = r;
                }
                l--, r++;
            }
        }
        
        
        return s.substr(ansS, mxLenPali);
    }
};