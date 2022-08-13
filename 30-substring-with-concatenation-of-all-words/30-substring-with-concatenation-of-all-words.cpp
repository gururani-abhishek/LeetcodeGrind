class Solution {
public:
    //str.substr(pos, len) -> str.substr(0, str.length());
    //will return entire string.
    vector<int> findSubstring(string s, vector<string>& words) {
        
        unordered_map<string, int> wordsMap;
        for(auto str: words) {
            wordsMap[str]++;
        }
        
        int windowSize = words[0].size() * words.size();
        //because I'm taking a substring, therefore it must be continuous 
        //right from 0th index.
        
        int idx = 0, wordSize = words[0].size();
        
        vector<int> res;
        while(idx + windowSize <= s.size()) {
            if(checkSubstr(wordsMap, s.substr(idx, windowSize), wordSize)) {
                res.push_back(idx);  
            }            
            
            idx++;
        }
    
        return res;
    }
    
private: 
    bool checkSubstr(unordered_map<string, int> wordsMap, string s, int windowSize) {
        for(int idx = 0; idx < s.size(); idx += windowSize) {
            string sub = s.substr(idx, windowSize);
            
            if(wordsMap.find(sub) != wordsMap.end()) {
                if(--wordsMap[sub] < 0) return false;                
            } else {
                return false;
            }
        }
        
        return true;
    }
};