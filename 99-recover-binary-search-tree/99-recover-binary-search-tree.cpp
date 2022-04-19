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
    TreeNode *firstNode, *secondNode, *prev;
    void recoverTree(TreeNode* root) {
        
        inOrder(root);
        
        int temp = firstNode -> val;
        firstNode -> val = secondNode -> val;
        secondNode -> val = temp;
        
    }
    
private:
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        
        inOrder(root -> left);
        if(firstNode == NULL && (prev != NULL && prev -> val >= root -> val)) {
            firstNode = prev;
        }
        
        if(firstNode != NULL && prev -> val >= root -> val) {
            secondNode = root;
        }

        prev = root;
        inOrder(root -> right);
    }
};