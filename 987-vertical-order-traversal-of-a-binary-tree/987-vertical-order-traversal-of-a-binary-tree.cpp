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
    map<int, map<int, multiset<int>>> rc;

    void fillrc(TreeNode* node, int c, int r) {
        if(node == NULL) return;
        
        rc[c][r].insert(node -> val);
        
        
        fillrc(node -> left, c -1, r + 1);
        fillrc(node -> right, c + 1, r + 1);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        int r = 0, c = 0;
        fillrc(root, c, r);
        
        for(auto c: rc) {
            vector<int> col;
            for(auto r: c.second) {
                col.insert(col.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
        
    }
};