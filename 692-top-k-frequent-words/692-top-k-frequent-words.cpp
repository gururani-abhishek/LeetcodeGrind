class Solution {
public:
    typedef pair<int, string> pi;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto u: words) freq[u]++;
        auto comp = [](const pi& a, const pi& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }else {
                return a.second < b.second;
            }
            
        };
        
        priority_queue<pi, vector<pi>, decltype(comp)> minHeap(comp);
        
        for(auto u: freq) {
            minHeap.push({u.second, u.first});
            if(minHeap.size() > k) minHeap.pop();
        }
        
        vector<string> ans;
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};