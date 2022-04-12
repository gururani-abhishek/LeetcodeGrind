class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>> adjList(parents.size());
        for(int i=1; i<parents.size(); i++) {
            adjList[parents[i]].push_back(i);
        }
        
        vector<int> size(parents.size(), 0);
        dfs(0, adjList, size);
        
        //now size holds my count of subtrees for every node plus 1
        vector<long long> score(parents.size(), 0);
        long long mx = 0;
        for(int i=0; i<parents.size(); i++) {
            long long prod = 1;
            prod = max(prod, (long long)parents.size() - size[i]);
            
            for(auto child: adjList[i]) {
                prod *= size[child];
            }
            
            mx = max(mx, prod);
            score[i] = prod;
        }
        
        long long ans  = 0;
        for(auto u: score) 
            ans += (u == mx);
        
        return ans;
    }
    
private: 
    int dfs(int srcNode, vector<vector<int>>& adjList, vector<int>& size) {
        int ans = 1;
        for(auto child: adjList[srcNode]) {
            ans += dfs(child, adjList, size);
        }
    
        return size[srcNode] = ans;
    }
};