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
    int count, ans;
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        inOrder(root);
        return ans;
    }
    
private:
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        
        inOrder(root -> left);
        if(!(--count)) {
            ans = root -> val;
            return;
        }
        inOrder(root -> right);
    }
};