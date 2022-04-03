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
    vector<int> inOrder;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        
        int l = 0, r = inOrder.size() -1;
        while(l < r) {
            if(inOrder[l] + inOrder[r] > k) r--;
            else if(inOrder[l] + inOrder[r] < k) l++;
            else return true;
        }
        
        return false;
    }
    
private: 
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        
        inorder(root -> left);
        inOrder.push_back(root -> val);
        inorder(root ->  right);
    }
};