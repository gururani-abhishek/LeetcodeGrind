class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        
        for(int i =0;  i<points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            double dist = sqrt(x*x + y*y);
            maxHeap.push({dist, {x, y}});
            
            if(maxHeap.size() > k) maxHeap.pop();
        }
    
        vector<vector<int>> ans(maxHeap.size());
        
        int i =0;
        while(!maxHeap.empty()) {
            int x = maxHeap.top().second.first;
            int y = maxHeap.top().second.second;
            
            ans[i].push_back(x);
            ans[i].push_back(y);
            maxHeap.pop();
            
        i++;
        }
        
        return ans;
    }
};

/*
points[i] = {points[0],  points[1]} //x, y 
dist = sqrt(x1^2 + x2^2);
O(nlogk)
*/