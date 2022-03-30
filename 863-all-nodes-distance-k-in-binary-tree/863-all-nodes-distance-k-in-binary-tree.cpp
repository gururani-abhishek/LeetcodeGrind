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
    unordered_map<TreeNode*, TreeNode*> cp;
//     void inorder(TreeNode* root) {
//         //if(root == NULL) return;
        
//         if(root -> left != NULL) {
//             cp[root -> left] = root;
//             inorder(root -> left);
//         }
        
//         if(root -> right != NULL) {
//             cp[root -> right] = root;
//             inorder(root ->  right);
//         }
//     }
    
    void inorder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
            while(!q.empty()) {
                int size = q.size();
                
                while(size--) {
                    TreeNode* node = q.front();
                    q.pop();
                    
                    if(node -> left != NULL) {
                        cp[node -> left] = node;
                        q.push(node -> left);
                    }
                    
                    if(node -> right != NULL) {
                        cp[node -> right] = node;
                        q.push(node -> right);
                    }
                }
            }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, bool> visited;
        inorder(root);
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
                
                if(!visited[node -> left] && node -> left != NULL) {
                    q.push(node -> left);
                    visited[node -> left] = true;   
                }
                
                if(!visited[node -> right] && node -> right != NULL) {
                    q.push(node -> right);
                    visited[node -> right] = true;
                }
                
                if(cp[node]  && !visited[cp[node]]) {
                    q.push(cp[node]);
                    visited[cp[node]] = true;
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
};