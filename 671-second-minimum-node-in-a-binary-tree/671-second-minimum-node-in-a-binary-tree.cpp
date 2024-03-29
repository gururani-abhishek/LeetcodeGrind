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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> uniqueVal;
        dfs(root, uniqueVal);
        if(uniqueVal.size() < 2) return -1;
        auto it = uniqueVal.begin();
        it++;
    
        return *it;
    }
    
private: 
    void dfs(TreeNode* root, set<int> &uniqueVal) {
        if(root == NULL) return;
        dfs(root -> left, uniqueVal);
        uniqueVal.insert(root -> val);
        dfs(root -> right, uniqueVal);
    }
};