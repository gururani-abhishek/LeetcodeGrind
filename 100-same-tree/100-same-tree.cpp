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
        if(p == NULL || q == NULL) return p == q;
        
        queue<TreeNode*> qP, qQ;
        qP.push(p);
        qQ.push(q);
        
        while(!qP.empty() && !qQ.empty()) {
            TreeNode* nodeP = qP.front();
            TreeNode* nodeQ = qQ.front();
            
            qP.pop();
            qQ.pop();
            
            
            //val should be same;
            if(nodeP -> val != nodeQ -> val) return false;
            
            //both should be null together, otherwise put them in queue;
            if(nodeP -> left != NULL && nodeQ -> left != NULL) {
                qP.push(nodeP -> left);
                qQ.push(nodeQ -> left);
            } else if(nodeP -> left != NULL || nodeQ -> left != NULL) return false;
            
            //both should be null together, otherwise put them in queue;
            if(nodeP -> right != NULL && nodeQ -> right != NULL) {
                qP.push(nodeP -> right);
                qQ.push(nodeQ -> right);
            } else if(nodeP -> right != NULL || nodeQ -> right != NULL) return false;
           
        }
    return true;
    }
    
};