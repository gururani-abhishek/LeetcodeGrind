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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int ans = 0;
        queue<TreeNode*> kyu;
        
        kyu.push(root);
        
        while(!kyu.empty()) {
            int size = kyu.size();
            ans++;
            
            while(size--) {
                TreeNode* node = kyu.front();
                kyu.pop();
            
                if(node -> left != NULL) kyu.push(node -> left);
                if(node -> right != NULL) kyu.push(node -> right);
            }
            
        }
        
        return ans;
    }
};