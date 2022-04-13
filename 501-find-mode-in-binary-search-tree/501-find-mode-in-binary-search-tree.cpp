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
    map<int, int> freq;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int mx = -1e9;
        for(auto u: freq) 
            mx = max(mx, u.second);
        
        vector<int> ans;
        
        for(auto u: freq) 
            if(u.second == mx) ans.push_back(u.first);
    
        return ans;
    }
    
    
private: 
    void dfs(TreeNode* node) {
        if(node == NULL) return;
        
        freq[node -> val]++;
        dfs(node -> left);
        dfs(node -> right);
    }
};