class Solution {
public:
    bool isPalindrome(string s) {
        //uppercase to lowercase
        //keep letters and numbers only
        //tc = O(n), sc = O(n);
        int n = s.size();
        string s1;
        for(int i=0; i<n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >='0' && s[i] <= '9') {
                if(s[i] >= 'A' && s[i] <= 'Z') s1 += s[i] + 32;
                else s1 += s[i];
            }    
        }
        int i =0, j = s1.length()-1;
        while(i < j) {
            if(s1[i] != s1[j]) return false;
            i++, j--;
        }
        
        return true;
    }
};