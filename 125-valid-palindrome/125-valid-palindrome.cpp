class Solution {
public:
    bool isPalindrome(string s) {
        //uppercase to lowercase
        //keep letters and numbers only
        //tc = O(n), sc = O(n);
        int n = s.size();
    
        int i =0, j = s.length()-1;
        
        bool fi = 0; 
        bool fj = 0;
        while(i < j) {
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >='0' && s[i] <= '9') {
                if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
                fi = 1;
            } 
            
            if(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z' || s[j] >= '0' && s[j] <= '9') {
                if(s[j] >= 'A' && s[j] <= 'Z') s[j] += 32;
                fj = 1;
            }
            
            if(fi && fj) {
                if(s[i] != s[j]) return false;
                i++, j--;
            } else if(!fi && !fj) i++, j--;
            else if(!fi) i++;
            else if(!fj) j--;
            
            
            fi = 0;
            fj = 0;
        }
        
        return true;
    }
};