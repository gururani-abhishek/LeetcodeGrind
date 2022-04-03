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
class BSTIterator {
public: 
    stack<TreeNode*> stk;
    bool who; //true for left, and false for right;
    
    BSTIterator(TreeNode* root, bool which) {
        who = which;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        who ? pushAll(node -> right) : pushAll(node -> left);
        return node -> val;
    }
    
private:
    void pushAll(TreeNode* node) {
        while(node != NULL) {
            stk.push(node);
            who ? node = node -> left : node = node -> right;
        }
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        
        int i = l.next(), j = r.next();
        
        while(i < j) {
            if(i + j == k)  return true;
            else if( i + j < k) i = l.next();
            else j = r.next();
        }
    return false;
    }
};