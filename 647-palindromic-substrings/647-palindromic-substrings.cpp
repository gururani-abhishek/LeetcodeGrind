class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();
        int res = 0;
        for(int idx=0; idx<size; idx++) {
            
            //type : aba
            int left = idx, right = idx;
            while(left >= 0 && right <= size && s[left] == s[right]) {
                res++;
                left--;
                right++;
            }
            
            left = idx; 
            right = idx + 1;
            while(left >= 0 && right <= size && s[left] == s[right]) {
                res++;
                left--;
                right++;
            }
        }
        
        
        return res;
    }
};