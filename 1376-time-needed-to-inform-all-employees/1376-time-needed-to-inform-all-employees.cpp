class Solution {
public:
    
    unordered_map<int, vector<int>> adjList;
    int mx = 0, ans = 0; 
    
    void dfs(int manager, vector<int>& informTime) {
        mx = max(mx, ans);
        for(auto u: adjList[manager]) {
            ans += informTime[manager];
            dfs(u, informTime);
            ans -= informTime[manager]; 
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //first we'll construct an adjacency list
        for(int i=0; i<n; i++) {
            if(manager[i] != -1) adjList[manager[i]].push_back(i);
        }
        
        //idea is too traverse depth wise in this graph, and look out for the max of sum of inform times.
        dfs(headID, informTime);
        return mx;
    }
};