class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length(), idx = 0; 
        string word = ""; 
        
        vector<string> res1; 
        
        // initial space skipping : 
        while(s[idx] == ' ') idx++;
        
        while(idx < n) {
            // word catching : 
            while(s[idx] != ' ' && idx < n) word += s[idx], idx++; 
            res1.push_back(word); 
            word = ""; 
            
            // space skipping : 
            while(s[idx] == ' ' && idx < n) idx++; 
        }
    
        // reverse the words : 
        reverse(res1.begin(), res1.end()); 
        
        string res = ""; 
        
        for(int idx = 0; idx < res1.size(); idx++) {
            
            string word = res1[idx]; 
            res += word; 
            if(idx != res1.size() -1) res += ' '; 
        }
        
        return res; 
    }
};