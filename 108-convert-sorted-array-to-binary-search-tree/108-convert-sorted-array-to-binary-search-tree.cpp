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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        TreeNode* root = nullptr;
        create(nums, left, right, root);
        
        return root;
    }
    
private: 
    void create(vector<int> &nums, int left, int right, TreeNode* &root) {
        if(left > right) {
            root = NULL;   
            return;
        }
        
        int mid = left + (right - left)/2;
        
        TreeNode* node = new TreeNode(nums[mid]);
        root = node;
        create(nums, left, mid-1, root -> left);
        create(nums, mid+1, right, root -> right);
        
    }
};