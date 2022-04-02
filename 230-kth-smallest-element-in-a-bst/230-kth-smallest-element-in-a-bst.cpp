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
    void inorder(TreeNode* node) {
        if(node -> left != NULL) inorder(node -> left);
        
        count--;
        //cout << count << " ";
        if(count == 0) {
                number = node -> val;
            }
        if(node -> right != NULL) inorder(node -> right);
    }
};