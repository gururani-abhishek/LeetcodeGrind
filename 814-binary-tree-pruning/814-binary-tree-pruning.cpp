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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        
        // for this root check if it contains 1 in it's left and right subtree
        if(checkForOnes(root) == false) {
            return nullptr;
        }
        
        root -> left = pruneTree(root -> left);
        root -> right = pruneTree(root -> right);
        
        return root;
    }
    
private : 
    bool checkForOnes(TreeNode* node) {
        if(node == nullptr) return false;
        
        if(node -> val == 1) return true;
        
        return (checkForOnes(node -> left) || checkForOnes(node -> right));
    }
};