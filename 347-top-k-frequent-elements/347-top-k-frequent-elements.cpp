class Solution {
public:
    #define pi pair<int,int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto u: nums) freq[u]++;
        
        priority_queue<pi,  vector<pi>, greater<pi>> minHeap;        
        for(auto u: freq)  {
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

//1 -> 4
//2 -> 2
//3 -> 5



// max freq bottom 