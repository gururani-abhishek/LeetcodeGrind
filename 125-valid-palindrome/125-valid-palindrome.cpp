class Solution {
public:
    bool isPalindrome(string s) {
        //uppercase to lowercase: tolower() 
        //keep letters and numbers only: isalnum() checks if the number is alphabet numeric or not.
        //tc = O(n), sc = O(1);
        int n = s.size();
    
        int i =0, j = s.length()-1;
        
        while(i < j) {
            while(i < j && !isalnum(s[i])) {
                i++;
            }
            while(j > i && !isalnum(s[j])) {
                j--;
            }
            
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++, j--;
        }
        
        return true;
    }
};