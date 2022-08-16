class Solution {
public:
    // tc : O(n) //scanning string just once
    // sc : O(n)
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp;
        //mp[char] = {freq, idx};
        
        //scanning string, and mapping words, with freq and their idx
        for(int idx = 0; idx < s.length(); idx++) {
            mp[s[idx]].first++;
            mp[s[idx]].second = idx;
        }
        
        //scanning hashMap, ans returning the element(idx) with min Idx, whose 
        //freq is 1,  min Idx Because we have to return the <first unique char>
        int ans = INT_MAX;
        for(auto mappedValues : mp) {
            if(mappedValues.second.first == 1) {
                ans = min(ans, mappedValues.second.second);
            }
        }
                
        return ans == INT_MAX ? -1 : ans;
    }
};