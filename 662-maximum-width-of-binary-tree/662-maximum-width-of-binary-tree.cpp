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
        
        //I'm applying a hack here, subtracting each serial with the max serial of that level
        
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        int ans = 0;
        
        while(!q.empty()) {
            int size = q.size();
            int first = q.front().second, last = q.back().second;
            ans = max(ans, last - first +1);
            
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front().first;
                int index = q.front().second - last;
                q.pop();
                
                if(node -> left != NULL) q.push({node -> left, 2*index + 1});
                if(node -> right != NULL) q.push({node -> right, 2*index + 2});
            }
        }
        
        return ans;
    }
};