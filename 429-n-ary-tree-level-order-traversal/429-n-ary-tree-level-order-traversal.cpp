/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root == nullptr) return {};
        
        queue<Node*> q; // take a queue
        q.push(root); // push in root
        
        
        vector<vector<int>> res; // will hold nodes level order wise 
        
        // explore BFS -> 
        while(!q.empty()) {
            int size = q.size();
            
            vector<int> res1; // store nodes for this level
            // explore this level -> 
            while(size--) {
            
                auto node = q.front(); // explore this node
                res1.push_back(node -> val);
                
                // store all the children to queue
                for(auto neighbors : node -> children) {
                    q.push(neighbors);
                }
                
                q.pop(); // remove this node
            }
            
            res.push_back(res1); // push this whole level in my res
        }
        
        
        return res; // return res
    }
};