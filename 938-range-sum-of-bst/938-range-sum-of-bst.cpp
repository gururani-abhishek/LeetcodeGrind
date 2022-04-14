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
    int ans = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        preOrder(root, low, high); 
        return ans;
    }
    
private: 
    void preOrder(TreeNode* root, int low, int high) {
        if(root == NULL) return;
        
        if(root -> val >= low && root -> val <= high) {
            ans += root -> val;
            preOrder(root -> left, low, high);
            preOrder(root -> right, low, high);   
        } else if(root -> val < low) preOrder(root -> right, low, high);
        else preOrder(root -> left, low, high);
        
    }
};