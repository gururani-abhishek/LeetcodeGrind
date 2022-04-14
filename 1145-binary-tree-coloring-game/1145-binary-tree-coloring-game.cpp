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
    int arr[3];
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        findAndCount(root, x);
        arr[2] = n - arr[0] - arr[1] - 1;
        sort(arr, arr+3);
        
        if(arr[2] > arr[0] + arr[1]) return true;
        return false;
    }
private: 
    int findAndCount(TreeNode* root, int x) {
        if(root == NULL) return 0;
        int l = findAndCount(root -> left, x);
        int r = findAndCount(root -> right, x);
        
            if(root -> val == x) {
                arr[0] = l;
                arr[1] = r;
            }
        
        return l+r+1;
    }
    
};