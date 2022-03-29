/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        tracePath(root, p -> val, pathP);
        tracePath(root, q -> val, pathQ);
        
        int i;
        for(i=0; i<min(pathP.size(), pathQ.size()) && pathP[i] -> val == pathQ[i] -> val; i++);
        
        return pathP[i-1];
    }
private: 
    bool tracePath(TreeNode* node, int target, vector<TreeNode*>& path) {
        if(node == NULL) return false;
        path.push_back(node);
        if(node -> val == target) return true;
        
        if(tracePath(node -> left, target, path) || tracePath(node -> right, target, path)) 
            return true;
        
        path.pop_back();
        return false;
    }
};