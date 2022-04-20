class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        
        for(int i=0; i<s.size(); i++) {
            freq[s[i]]++;    
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for(auto u: freq) 
            maxHeap.push({u.second, u.first});
        
        queue<pair<int, pair<int, char>>> q;
        
        int i = 0;
        string ans = "";
        while(!maxHeap.empty() || !q.empty()) {
            i++;
            
                
            if(!maxHeap.empty()) {
                ans += maxHeap.top().second;
                int cnt = maxHeap.top().first - 1;
                if(cnt) {
                    q.push({i+1, {cnt, maxHeap.top().second}});
                }
                
                maxHeap.pop();
            }
            
            if(!q.empty() && q.front().first == i) {
                maxHeap.push({q.front().second.first,  q.front().second.second});
                q.pop();
            }
        }
        
        if(i != s.size()) return "";
        return ans;
    }
};

