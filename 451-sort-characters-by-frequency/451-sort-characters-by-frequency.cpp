class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto u: s) freq[u]++;
        
        vector<pair<int, char>> charInt;
        for(auto u: freq) 
            charInt.push_back({u.second, u.first});
        
        sort(charInt.begin(), charInt.end(), greater<pair<int, char>>());
        
        string ans = "";
        for(auto u: charInt) {
            ans += string(u.first, u.second);
        }
        
        return ans;
    }
};