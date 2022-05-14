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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == NULL || q == NULL) {
            return p == q;
        }
        
        
        queue<TreeNode*> P, Q;
        P.push(p);
        Q.push(q);
        
        while(!P.empty() && !Q.empty()) {
            TreeNode* nodeP = P.front();
            TreeNode* nodeQ = Q.front();
            P.pop();
            Q.pop();
            
            if(nodeP -> val != nodeQ -> val) return false;
            
            if(nodeP -> left == NULL && nodeQ -> left != NULL || nodeP -> left != NULL && nodeQ -> left == NULL) {
                return false;
            } else if(nodeP -> left != NULL && nodeQ -> left != NULL) {
                Q.push(nodeQ -> left);
                P.push(nodeP -> left);
            }
            
            if(nodeP -> right == NULL && nodeQ -> right != NULL || nodeP -> right != NULL && nodeQ -> right == NULL) {
                return false;
            } else if(nodeP -> right != NULL && nodeQ -> right != NULL) {
                Q.push(nodeQ -> right);
                P.push(nodeP -> right);
            }
        }
        
        return true;
    }
};