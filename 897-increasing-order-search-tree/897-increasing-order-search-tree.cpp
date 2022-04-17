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
    vector<int> inc;
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        TreeNode *result = NULL, *prev;
        for(auto u: inc) {
            TreeNode* cur = new TreeNode(0);
            cur -> val = u;
            cur -> left = NULL;
            
            if(result == NULL) {
                result = cur;
            } else {
                prev -> right = cur;
            }
            
            prev = cur;
        }
        
        
        return result;
    }
    
private:
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        inOrder(root -> left);
        inc.push_back(root -> val);
        inOrder(root -> right);
    }
    
    
};