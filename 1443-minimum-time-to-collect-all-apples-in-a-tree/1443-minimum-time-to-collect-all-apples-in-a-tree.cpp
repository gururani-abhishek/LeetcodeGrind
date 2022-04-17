class Solution {
public:
    vector<vector<int>> adjList;
    vector<bool> visited;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //create an adjacency list to better represent the data.
        adjList.resize(n);
        visited.resize(n, false);
        
        for(int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        //once the adjList is created, edges is of no more use.
        int distance = dfs(0, adjList, hasApple);
        return distance == 0? 0: 2*(distance -1);
    }
private:
    int dfs(int root, vector<vector<int>>& adjList, vector<bool>& hasApple) {
        int ans = 0;

        //plain dfs, with internal base case when adjList will be totally explored(i.e. will hit NULL node)
        visited[root] = true;
        for(auto child: adjList[root]) {
            if(!visited[child]) {
                ans += dfs(child, adjList, hasApple);
            }
        }
        
        //this is the highlight, two scenerios:
        //1: the node for this recursion stack has an apple then return whatever the answer was plus 1
        //2: this node's any descendant was an apple, so it'll be counted. 
        
        return (hasApple[root] || ans > 0) ? (1 + ans) : 0;
    }
};