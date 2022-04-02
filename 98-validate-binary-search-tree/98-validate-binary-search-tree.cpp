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
    bool isValidBST(TreeNode* root) {
        long long int l = LLONG_MIN, r = LLONG_MAX;
        return preorder(root, l, r);
    }
private: 
    bool preorder(TreeNode* root, long long int l, long long int r) {
        
        if(root == NULL) return true;
        //cout << root -> val << " " << l << " " << r << endl;
        
        if(root -> val <= l || root -> val >= r) return false;
        
        return preorder(root -> left, l, root -> val) && preorder(root -> right, root -> val, r);
    }
};