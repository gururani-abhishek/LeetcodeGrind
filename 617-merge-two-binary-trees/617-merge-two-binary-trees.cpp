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
    //by reference pass krne ka mtlb hai "wahi pass krna" and 
    //by value pass krne ka mtlb hai "uska jaisa pass krna"
    //uska jaisa, uske jaisa hoga, no doubt, but wo nahi hoga.
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //I'm creating an entirely new tree, whose root node is being pointed by
        // TreeNode type pointer : "newTreeRootNode"
        TreeNode* newTreeRootNode = nullptr; // or TreeNode* newTreeRootNode(nullptr)
        
        create(root1, root2, newTreeRootNode);  //function to create a new merged tree.
        
        return newTreeRootNode;
    }
    
private: 
    
    void create(TreeNode* r1, TreeNode*  r2, TreeNode* & root) {
        if(!r1 && !r2) return;
        if(r1 && !r2) {
            //great, create a new node, where val = r1 -> val and left and right will be nullptr;
            TreeNode* node = new TreeNode(r1 -> val);
            root = node;
            
            create(r1 -> left, r2, root -> left);
            create(r1 -> right, r2, root -> right);
        } else if(!r1 && r2) {
            TreeNode* node = new TreeNode(r2 -> val);
            root = node;
            
            create(r1, r2 -> left, root -> left);
            create(r1,  r2 -> right, root -> right);
        } else {
            TreeNode* node = new TreeNode(r1 -> val + r2 -> val);
            root = node;
            
            create(r1 -> left, r2 -> left, root -> left);
            create(r1 -> right, r2 -> right, root -> right);
        }
        
    }
};