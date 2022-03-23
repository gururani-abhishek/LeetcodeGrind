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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
    
private: 
    void postOrder(TreeNode* node, vector<int>& ans) {
        if(node == NULL) return;
        if(node -> left != NULL) postOrder(node -> left, ans);
        if(node -> right != NULL) postOrder(node -> right, ans);
        ans.push_back(node -> val);
    }
};