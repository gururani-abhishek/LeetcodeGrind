/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// what is the  difference beetween copy and clone?
class Solution {
public:
    // I'll traverse my original node, and every node I'll create a newClone node,  with same value  
    // and same neighbors. 
    
    Node* cloneGraph(Node* node) {
        if(node  == nullptr) return node;
        
        unordered_map<Node*, Node*> oldNew; // it contains new cloned nodes for old nodes.
        
        clone(node, oldNew);
        return oldNew[node]; 
    }
private: 
    Node* clone(Node* node, unordered_map<Node*, Node*> &oldNew) {
        // if its clone is already created : 
        if(oldNew.find(node) != oldNew.end()) return oldNew[node];
        
        // if here it means that the clone isn't created : 
        // oldNew[node] = new Node(node -> val); // clone with same value added. connection missing.
        Node* clonedNode = new Node(node -> val);
        oldNew[node] = clonedNode;
        for(auto adjNode : node -> neighbors) {
                // (oldNew[node] -> neighbors).push_back(clone(adjNode, oldNew));
                (clonedNode -> neighbors).push_back(clone(adjNode, oldNew));
        }
        
        // return oldNew[node];
        return clonedNode;
        
    }
};