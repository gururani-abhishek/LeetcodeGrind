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
    int mx = INT_MIN;
    int maxPathSum(TreeNode* root) {

        height(root);
        return mx;
    }
    
    int height(TreeNode* node) {
        if(node == NULL) return 0;
        
        int lh = max(0, height(node -> left));
        int rh = max(0, height(node -> right));
        
        mx = max(mx, lh + rh + node -> val);
        
        return node -> val + max(lh, rh);
    }
};