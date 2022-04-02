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
    int count, number;
    int kthSmallest(TreeNode* root, int k) {
        
        count = k;
        inorder(root);
        return number;
    }
    
private: 
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        
        inorder(root -> left);
        count--;
        if(count == 0) {
            number = root -> val;
        }
        inorder(root -> right);
    }
};