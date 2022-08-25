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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        
        unordered_map<Node*, Node*> oldNew;
        return clone(node, oldNew);
    }

private: 
    Node* clone(Node* node, unordered_map<Node*, Node*> &oldNew) {
        
            Node* clonedNode = new Node(node -> val);
            oldNew[node] = clonedNode; // I've mapped old node with new clonedNode
        // this will be used further when I'll hop on to this node again.
            
            // explore all the neighbors :
            for(auto adjNode : node -> neighbors) {
                // if this neighbor has already been cloned, find it in oldNew
                // and push it in the neighbors list in clonedNode
                
                if(oldNew.find(adjNode) != oldNew.end()) {
                    (clonedNode -> neighbors).push_back(oldNew[adjNode]);
                } else {
                    // if not in newOld, then call the recursive function
                    // where you'll create the new clone and then pass it back
                    (clonedNode -> neighbors).push_back(clone(adjNode, oldNew));
                } 
            }
        // if here it means that this clonedNode is now made.
        // Just return it for the previous recursion call : 
        
        return clonedNode;
    }
};