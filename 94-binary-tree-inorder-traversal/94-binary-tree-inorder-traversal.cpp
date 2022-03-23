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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        
        while(1) {
            if(node != NULL) {
                stk.push(node);
                node = node -> left;
            }else {
                if(stk.empty() == true) break;
                node = stk.top();
                stk.pop();
                
                ans.push_back(node -> val);
                node = node -> right;
            }
        }
        
        return ans;
    }
};