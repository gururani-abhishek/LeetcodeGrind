class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> freq;
        for(auto u: s) freq[u]++;
        auto comp = [](const pair<int, char>& a, const pair<int, char>& b) {
          if(a.first != b.first) {
              return a.first < b.first;
          } else {
              return a.second > b.second;
          }
        };
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> maxHeap(comp);
        
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