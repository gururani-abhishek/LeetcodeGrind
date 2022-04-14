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
    TreeNode* redNode;
    int arr[3];
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        findRedNode(root, x);
        //cout  << cln << " " << crn;
        arr[2] = n - arr[0] - arr[1] - 1;
        sort(arr, arr+3);
        
        if(arr[2] > arr[0] + arr[1]) return true;
        return false;
    }
private: 
    void findRedNode(TreeNode* root, int x) {
        if(root  == NULL) return;
        
        if(root -> val == x) {
            arr[0] = countNodes(root -> left);
            arr[1] = countNodes(root -> right);
            return;
        }
        
        findRedNode(root -> left, x);
        findRedNode(root -> right, x);
    }
    
    int countNodes(TreeNode* node) {
        if(node == NULL) return 0;
        return (1+ countNodes(node -> left) + countNodes(node -> right));
    }
};