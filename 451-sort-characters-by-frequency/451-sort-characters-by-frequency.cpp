class Solution {
public:
    #define pi pair<int, char>
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        for(int i=0; i<s.length(); i++) 
            freq[s[i]]++;
        
        priority_queue<pi> maxHeap;
        
        for(auto u: freq) 
            maxHeap.push({u.second, u.first});
        
        string ans = "";
        while(!maxHeap.empty()) {
            int size = maxHeap.top().first;
            while(size--) {
                ans += maxHeap.top().second;
            }
            
            maxHeap.pop();
        }
        
        return ans;
    }
};