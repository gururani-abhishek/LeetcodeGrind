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
    vector<double> averageOfLevels(TreeNode* root) {
        
        // going for the level order traversal
        queue<TreeNode*> q; // will hold my nodes
        q.push(root); // pushing in the root
        
        
        vector<double> res; // will store the average for every level. 
        
        while(!q.empty()) {
            int size = q.size();
            int noOfNodesLevel = size;
            double levSum = 0; // will sum up one individual level
            while(size--) {
                
                TreeNode* node = q.front(); // taking a node and exploring it  
                levSum += node -> val; // adding node val to levSum
                cout << levSum;
                // push in left and right nodes if they exist : 
                if(node -> left != nullptr) q.push(node -> left);
                if(node -> right != nullptr) q.push(node -> right);
                
                q.pop(); // removing this already explored node from the queue
            }
            
            res.push_back(levSum/noOfNodesLevel); // pushing average of this level to levSum
        }
        
        return res;
    }
};