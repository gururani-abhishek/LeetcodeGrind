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
    int ans;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        dfs(root, targetSum);
        return ans; 
    }
private: 
    void dfs(TreeNode* root, int targetSum) {
        if(root == NULL) return;
        
        dfs(root -> left, targetSum);
        countPath(root, (long long)targetSum);
        dfs(root -> right, targetSum);
    }
    
    void countPath(TreeNode* node, long long targetSum) {
        if(node == NULL) return;
        
        if(targetSum - node -> val == 0) {
            ans++;
        }
        
        countPath(node -> left, targetSum - node -> val);
        countPath(node -> right, targetSum - node -> val);
    }
};