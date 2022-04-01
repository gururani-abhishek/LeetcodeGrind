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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return root = new TreeNode(val, NULL, NULL);
        }
        TreeNode* root1 = root;
        TreeNode* rootP;
        int l1 = 0, l2 = 0;
        
        while(root1!= NULL) {
            rootP = root1;
            l1 = l2 = 0;
            if(root1 -> val > val) {
                root1 = root1 -> left;
                l1 = 1;
            } else {
                root1 = root1 -> right;
                l2 = 1;
            }
            }
        
        if(l1) rootP -> left = new TreeNode(val, NULL, NULL);
        else rootP -> right = new TreeNode(val, NULL, NULL);
        
        
        return root;
    }
};