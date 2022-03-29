/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        //four probable cases:  
        //1> left == NULL && right == NULL return NULL
        //2> left != NULL && right == NULL return left
        //3> left == NULL && right != NULL return right
        //4> left != NULL && right != NULL return root
        
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
    
};