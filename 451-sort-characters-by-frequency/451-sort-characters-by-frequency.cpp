class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> freq;
        for(auto u: s) freq[u]++;
        
        priority_queue<pair<int, char>> maxHeap;
        
        for(auto u: freq) 
            maxHeap.push({u.second, u.first});
        
        while(!maxHeap.empty()) {
            auto it = maxHeap.top();
                for(int i =0; i<it.first; i++) {
                   ans.push_back(it.second); 
                }
            maxHeap.pop();
        }
        
        return ans;
    }
    
};