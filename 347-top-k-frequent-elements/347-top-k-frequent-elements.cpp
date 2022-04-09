class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto u: nums) freq[u]++;
        
        priority_queue<pi, vector<pi>,  greater<pi>> minHeap; //declaration of a minHeap.
        
        for(auto u: freq) {
            minHeap.push({u.second, u.first});
            
            if(minHeap.size() > k) minHeap.pop();
        }
        
        vector<int> ans;
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return ans;
    }
};