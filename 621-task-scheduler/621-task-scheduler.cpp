class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto u: tasks) {
            freq[u]++;
        }
        
        priority_queue<int> maxHeap; //stores only freq;
        for(auto u: freq) {
            maxHeap.push(u.second); 
        }
        
        queue<pair<int, int>> kyu; //freq, and next time after cooldown.
        
        int time = 0;
        while(!maxHeap.empty()  || !kyu.empty()) {
            time++;
            
            if(!maxHeap.empty()) {
                int count = maxHeap.top() -1;
                if(count) kyu.push({count, time + n});
                maxHeap.pop();
            }
            
            if(!kyu.empty() && kyu.front().second == time) {
                maxHeap.push(kyu.front().first);
                kyu.pop();
            }
            
        }
        
        return time;
    }
};