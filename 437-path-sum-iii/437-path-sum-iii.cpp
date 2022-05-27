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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            dfs(node, (long long)targetSum);
            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
        }
        
        
        return ans; 
    }

private: 
    void dfs(TreeNode* node, long long targetSum) {
        if(node == NULL) return;
        
        if(node -> val == targetSum) ans++;
        
        dfs(node -> left, targetSum - node -> val);
        dfs(node -> right, targetSum - node -> val);
    }
};


//treat every node as root 
//tc : O(nsquared)
//sc : constant, recursion stack space.