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
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
    
        map<int, map<int, multiset<int>>> rc;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            auto nodeData = q.front();
            q.pop();
            int x = nodeData.second.first; 
            int y = nodeData.second.second;
            
            auto node = nodeData.first;
            rc[x][y].insert(node -> val);
            if(node -> left != NULL) 
                q.push({node -> left, {x -1, y +1}});
            
            if(node -> right != NULL) 
                q.push({node -> right, {x +1, y +1}});
            
            
            }
                       
            for(auto u: rc) {
                vector<int> tmp;
                for(auto p: u.second) {
                    tmp.insert(tmp.end(), p.second.begin(), p.second.end());
                }
                ans.push_back(tmp);
            }         
            
      
        return ans;
        
    }
};