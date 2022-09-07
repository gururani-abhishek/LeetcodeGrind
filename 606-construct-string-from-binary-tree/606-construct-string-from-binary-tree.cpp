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
    string tree2str(TreeNode* root) {
        if(root == nullptr) return ""; // return empty string 

        // preorder traversal -> 
        string output = to_string(root -> val);

        // using 2nd observation -> 
        if(root -> left != nullptr || root -> right != nullptr) {
            output += '(' + tree2str(root -> left) + ')';
        }
        
        // using 3rd observation -> 
        if(root -> right != nullptr) {
            output += '(' + tree2str(root -> right) + ')';
        }
        
        // for every state return this in the end while backtracking. 
        return output; 
        
    }
};

// 3 key observations -> 
// 1 -> root ke niche har node ke shuruaat and end mai '(' and this ')'
// 2 -> agr kisi node ka left na ho par right ho, ya left ho -> do 1 for left
// 3 -> agr kisi ka right ho to do 1 for right