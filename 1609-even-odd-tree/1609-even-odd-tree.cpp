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
    bool isEvenOddTree(TreeNode* root) {
        //even indexing: odd values and in increasing fashion
        //odd indexing: even values and in decreasing fashion.
        
        if(root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        
        int flag = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            //vector<int> v1;
            for(int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();
            
                if(flag == 0 && node -> val %2 == 0) return false;
                else if(flag == 1 && node -> val %2 == 1) return false;
                
                v.push_back(node -> val);
                //v1.push_back(node -> val);
                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
            }
            
            if(flag == 0) {
                flag = 1;
                for(int i=0; i<v.size()-1; i++) {
                    if(v[i] >= v[i+1]) return false;
                }
            }else {
                flag = 0;
                for(int i=0; i<v.size()-1; i++) {
                    if(v[i] <= v[i+1]) return false;
                }
            }
            
        }
        return true;
    }
};