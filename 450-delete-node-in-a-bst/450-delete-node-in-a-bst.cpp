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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        if(root -> val == key) return helper(root);
        
        TreeNode* cur = root;
        
        while(cur != NULL) {
             if(cur -> val > key) {
                if(cur -> left != NULL && cur -> left -> val == key) {
                    cur -> left = helper(cur -> left);
                    break;
                } else {
                    cur = cur -> left;
                }      
             } else {
                 if(cur -> right != NULL && cur -> right -> val == key) {
                     cur -> right = helper(cur -> right);
                     break;
                 } else {
                     cur = cur -> right;
                 }
             }
        }
        
        return root;
        
    }
    
    TreeNode* helper(TreeNode* node) {
        if(node -> left == NULL) return node -> right;
        if(node -> right == NULL) return node -> left;
        
        //both the children exist.
        TreeNode* point = findRightMost(node -> left);
        point -> right = node -> right;
        return node -> left;
    }
    
    TreeNode* findRightMost(TreeNode* node) {
        if(node -> right == NULL) return node;
        
        return findRightMost(node -> right);
    }
    
    
};