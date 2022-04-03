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
    stack<TreeNode*> stk, stk2;
    bool findTarget(TreeNode* root, int k) {
        pushLeftAll(root);
        pushRightAll(root);
        int i = outFront(), j = outBack();
        
        while(i < j) {
            if(i + j ==  k) return true;
            else if(i + j < k) i = outFront();
            else j =  outBack();
        }
        
        return false;
    }
    
    int outBack() {
        TreeNode* node = stk2.top();
        stk2.pop();
        pushRightAll(node -> left);
        return node -> val;
    }
    
    int outFront()  {
        TreeNode* node = stk.top();
        stk.pop();
        pushLeftAll(node -> right);
        return node -> val;
    }
    
    void pushLeftAll(TreeNode* root) {
        while(root != NULL) {
            stk.push(root);
            root = root -> left;
        }
    }
    
    void pushRightAll(TreeNode* root) {
        while(root != NULL) {
            stk2.push(root);
            root = root -> right;
        }
    }
};