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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        unsigned long long maxWidth = 0;
        
        while(!q.empty()) {
            int size = q.size();
            unsigned long long first = q.front().second, last = q.back().second;
            maxWidth = max(maxWidth, last - first + 1);
            while(size--) {
                TreeNode* node = q.front().first;
                unsigned long long dadSerial = q.front().second - 1;
                q.pop();
                
                if(node -> left != NULL) q.push({node -> left, 2*dadSerial + 1});
                if(node -> right != NULL) q.push({node -> right, 2*dadSerial + 2});
            }
            
        }
        
        return maxWidth;
    }
};