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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans1;
        dfs(root, targetSum, ans1);
            
        return ans;
    }

private: 
    void dfs(TreeNode* root, int targetSum, vector<int>& ans1) {
        if(root == NULL) return;
        
        if(root -> left == NULL && root -> right == NULL && targetSum - root -> val == 0) {
            ans1.push_back(root -> val);
            ans.push_back(ans1);
            ans1.pop_back();
            return;
        }
        
        ans1.push_back(root -> val);
        dfs(root -> left, targetSum - root -> val, ans1);
        dfs(root -> right, targetSum - root -> val, ans1);
        ans1.pop_back();
    }
};