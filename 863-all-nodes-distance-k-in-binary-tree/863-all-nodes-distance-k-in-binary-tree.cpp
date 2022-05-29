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
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        
        int dist = 0;
        
        visited[target] = true;
        while(!q.empty()) {
            if(dist++ == k) break;
            int size = q.size();
            while(size--) {
            TreeNode* node = q.front();
            q.pop();
            visited[node] = true;
            if(node -> left != NULL && !visited[node -> left]) {
                q.push(node -> left);
            }
            
            if(node -> right != NULL && !visited[node -> right]) {
                q.push(node -> right);
            }
            
            if(parent[node] && !visited[parent[node]]) {
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

