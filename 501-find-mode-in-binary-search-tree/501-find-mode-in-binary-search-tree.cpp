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
    vector<int> ans;
    int predecessor = INT_MIN, curFreq = 0, maxFreq = 0;
    
    vector<int> findMode(TreeNode* root) {
        //inorder traversal traverse nodes in their ascending order
        inOrder(root);
        
        return ans;
    }
private: 
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        
        inOrder(root -> left);
        
        if(root -> val == predecessor) curFreq++;
        else curFreq = 1;
        
        if(curFreq > maxFreq) {
            ans.clear();
            ans.push_back(root -> val);
            maxFreq = curFreq;
        } else if(curFreq == maxFreq) ans.push_back(root -> val);

        predecessor = root -> val;
        
        inOrder(root -> right);
        
    }
};