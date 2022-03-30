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
        queue<pair<TreeNode*, unsigned long long >> q;
        
        q.push({root, 0});
        unsigned long long ans = 0;
        
        while(!q.empty()) {
            int size = q.size();
            ans = max(ans, q.back().second - q.front().second + 1);
            
            while(size--) {
                unsigned long long currSerial = q.front().second - 1;
                TreeNode* node = q.front().first;
                
                if(node -> left != NULL) q.push({node -> left, 2*currSerial +1});
                if(node -> right != NULL) q.push({node -> right, 2*currSerial +2});
                
                q.pop();
            }
        }
        
        return ans;
        
    }
};