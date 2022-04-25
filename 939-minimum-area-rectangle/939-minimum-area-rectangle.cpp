class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
       //idea is to store all the corresponding y co's for each x
        
        unordered_map<int, unordered_set<int>> map;
        for(auto u: points) {
            map[u[0]].insert(u[1]);
        }
        int n = points.size();
        
        int ans = INT_MAX;
        bool flag = 0;
        for(int i=0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                //they'll form the diagonal of our rectangle
                if(x1 != x2 && y1 != y2) {
                    //let's now find the other two
                    if(map[x1].find(y2) != map[x1].end() && map[x2].find(y1) != map[x2].end()) {
                        flag = 1;
                        ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
                    }
                }
            }
        }
        
        return flag ? ans : 0;
    }
};

// x1,y2       x2,y2
        
// x1,y1       x2,y1