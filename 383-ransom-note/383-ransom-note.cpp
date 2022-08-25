class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(int idx=0; idx<magazine.length(); idx++) {
            freq[magazine[idx]]++;
        }
        
        for(int idx= 0; idx < ransomNote.length(); idx++) {
            if(freq.find(ransomNote[idx]) == freq.end()) return false;
            if(freq[ransomNote[idx]] == 0) return false;
            freq[ransomNote[idx]]--;
        }
        
        return true;
    }
};