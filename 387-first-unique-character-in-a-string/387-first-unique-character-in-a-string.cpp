class Solution {
public:
    // tc : O(n)
    // sc : O(n)
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        //mapping characters of the string to their frequencies
        for(int idx = 0; idx < s.length(); idx++) {
            mp[s[idx]]++;
        }
        
        //traversing the array and returning the first element(idx),
        //which has a frequency 1
        for(int idx = 0; idx < s.length(); idx++) {
            if(mp[s[idx]] == 1) return idx;
        }
        
        return -1;
    }
};