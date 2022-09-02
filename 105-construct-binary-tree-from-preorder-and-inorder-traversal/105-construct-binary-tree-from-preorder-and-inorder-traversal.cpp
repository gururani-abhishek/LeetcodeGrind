/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // map to easily locate the preorder root element
        // first element of preorder will be root element for that subtree
        
        unordered_map<int, int> rootIdx; // is storing the idx of root element(i.e. first element of preorder traversal)  
        // map inorder elements with their indices : 
        for(int idx =0; idx < inorder.size(); idx++) {
            rootIdx[inorder[idx]] = idx;
        }
        
        // with every recursion call I'll update my preorder and inorder traversals : 
        // I need some pointers to do that effectively. 
        
        int preStart = 0, preEnd = preorder.size() -1, inStart = 0, inEnd = inorder.size() -1;
        return build(preorder, preStart, preEnd, inorder, inStart, inEnd, rootIdx);
    }
    
private : 
    TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &rootIdx) {
        if(inStart > inEnd) return nullptr;
        
        // create the new node, i.e. first element in our preorder -> 
        TreeNode* node = new TreeNode(preorder[preStart]);
        
        int idx = rootIdx[preorder[preStart]]; // finding the idx of my root element in inorder vector 
        int nodesOnLeft = idx - inStart; 
        
        // update all the pointers : 
        // inStart same 
        // inEnd = idx -1
        // preStart =  preStart + 1;
        // preEnd = preStart + nodesOnLeft
    
        
        // call the left subtree 
        node -> left = build(preorder, preStart+1, preStart + nodesOnLeft, inorder, inStart, idx -1, rootIdx);
        
        // update all the pointers :
        // inStart = idx + 1;
        // inEnd same
        // preStart = preStart + nodeOnLeft + 1
        // preEnd same
        
        
        // call the right subtree 
        node -> right = build(preorder, preStart + nodesOnLeft + 1, preEnd, inorder, idx + 1, inEnd, rootIdx);
        
        
        return node;
    
    
    }
};

// LrootR -> inorder = [9,3,15,20,7]
// rootLR -> preorder = [3,9,20,15,7]

 /*
        3 
    9       20
          15   7
 
 */