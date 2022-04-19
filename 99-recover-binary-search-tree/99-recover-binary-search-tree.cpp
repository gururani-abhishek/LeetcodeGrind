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
    void recoverTree(TreeNode* root) {
        vector<int> bst;
        inOrder(root, bst, 1);
        
        //for(auto u: bst) cout << u << " ";
        sort(bst.rbegin(), bst.rend());
        
        inOrder(root, bst, 2);
    }
    
private: 
    void inOrder(TreeNode* root, vector<int>& bst, int type) {
        if(root == NULL) return;
        inOrder(root -> left, bst, type);
        if(type == 1) bst.push_back(root -> val);
        if(type == 2) {
            root -> val = bst[bst.size() -1];
            bst.pop_back();
        }
        inOrder(root -> right, bst, type);
    }
};