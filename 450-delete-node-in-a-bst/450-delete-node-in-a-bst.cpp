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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        if(root -> val == key) return reConnect(root);
        
        TreeNode* cur = root;
        while(cur != NULL) {
            // if(cur -> val == key) {
            //     cur = reConnect(cur);
            //     break;
            // }else if(cur -> val < key) cur = cur -> right;
            // else cur = cur -> left; 
            //I was sending that node instead of the parent node, was messing up pointers.
            if(cur -> val > key) {
                if(cur -> left != NULL && cur -> left -> val == key) {
                    cur -> left = reConnect(cur -> left);
                    break;
                } else {
                    cur = cur -> left;
                }
            } else {
                if(cur -> right != NULL && cur -> right -> val == key) {
                    cur -> right = reConnect(cur -> right);
                    break;
                } else {
                    cur = cur -> right;
                }
            }
            
        }
        
        return root;
    }
private: 
    TreeNode* reConnect(TreeNode* node) {
        //if it has only 1 child
        if(node -> right == NULL) return node -> left;
        if(node -> left == NULL) return node -> right;
            
        //if it has 2 children
        TreeNode* point = findLeftMost(node -> right);
        point -> left = node -> left;
        
        return node -> right;
    }
    
   TreeNode* findLeftMost(TreeNode* node) {
       while(node -> left != NULL) node = node -> left;
       return node;
   }
};