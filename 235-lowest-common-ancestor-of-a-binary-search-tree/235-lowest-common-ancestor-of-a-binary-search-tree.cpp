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
        if(root -> val < p -> val && root -> val < q -> val) return lowestCommonAncestor(root -> right, p, q);
        else if(root -> val > p -> val && root -> val > q -> val) return lowestCommonAncestor(root -> left, p, q);
    
        return root;
    }
};

//take {p,q} as a package, traverse to them using the properties of BST, and the moment they divide, that's our answer.