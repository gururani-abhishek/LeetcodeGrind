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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        else if(subRoot == NULL) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(sameTree(node, subRoot)) return true;
            
            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
        }
        
        return false;
    }

private:
    bool sameTree(TreeNode* node1, TreeNode* node2) {
        queue<TreeNode*> q1, q2;
        q1.push(node1);
        q2.push(node2);
        
        while(!q1.empty() && !q2.empty()) {
            TreeNode* nodeOne = q1.front();
            TreeNode* nodeTwo = q2.front();
            
            q1.pop();
            q2.pop();
            
            if(nodeOne -> val != nodeTwo -> val) return false;
            
            if(nodeOne -> left != NULL && nodeTwo -> left == NULL || nodeOne -> left == NULL && nodeTwo -> left != NULL) return false;
            else if(nodeOne -> left != NULL && nodeTwo -> left != NULL) {
                q1.push(nodeOne -> left);
                q2.push(nodeTwo -> left);
            }
            
            if(nodeOne -> right != NULL && nodeTwo -> right == NULL || nodeOne -> right == NULL && nodeTwo -> right != NULL) return false;
            else if(nodeOne -> right != NULL && nodeTwo -> right != NULL) {
                q1.push(nodeOne -> right);
                q2.push(nodeTwo -> right);
            }
            
        }
        
        return true;
    }
};