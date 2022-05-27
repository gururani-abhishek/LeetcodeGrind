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
    unordered_map<TreeNode*, TreeNode*> parent; //maps child to parent
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, bool> visited;
        dfs(root);
        queue<TreeNode*> q;
        q.push(target);
        
        int dist = 0;
        visited[target] = true;
        
        while(!q.empty()) {
            int size = q.size();
            
            if(dist++ == k) break;
            
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                
                //radially outward movement to: 
                
                //left child
                if(!visited[node -> left] && node -> left != NULL) {
                   visited[node -> left] = true;
                   q.push(node -> left); 
                }
                
                //right child
                if(!visited[node -> right] && node -> right != NULL) {
                    visited[node -> right] = true;
                    q.push(node -> right);
                }
                
                //parent
                if(parent[node] && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front() -> val);
            q.pop();
        }        
        
        return ans;
    }

private:
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        
        if(root -> left != NULL) {
            parent[root -> left] = root;
            dfs(root -> left);
        }
        
        if(root -> right != NULL) {
            parent[root -> right] = root;
            dfs(root -> right);
        }
    }
};


//idea is to move radially outward from our target node, 
//radially outward means, from node : to parent node, to left child, to right child.