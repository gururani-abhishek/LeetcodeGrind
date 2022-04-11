class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        //creating an adjacency list
        int n = parents.size();
        vector<vector<int>> adjList(n);
        vector<int> size(n, 0); //holds the size of subtrees for each node + 1(for that node)
        
        for(int i=1; i<n; i++) 
            adjList[parents[i]].push_back(i); //parent to child relationship    
        
        //adjList[0] -> 2, 4
        //adjList[2] -> 1, 3
        
        //calculating size of each subtree using dfs
        int srcNode = 0; //because I know parent node is 0th node
        dfs(srcNode, adjList, size);
        
        long long cnt =0, mx = 0;
        for(int i=0; i<n; i++) {
            long long pro = 1;
            pro = max(pro, (long long)n - size[i]);
            
            for(auto u: adjList[i]) 
                pro *= size[u];
            
            if(pro > mx) {
                cnt = 1;
                mx = pro;
            } else if(pro == mx) cnt++;
        }
        
        return cnt;
        
    }
private: 
    int dfs(int srcNode, vector<vector<int>>& adjList, vector<int>& size) {
        int ans = 1;
        for(auto child: adjList[srcNode]) 
            ans += dfs(child, adjList, size);
        
        return size[srcNode] = ans;
    }
    
};