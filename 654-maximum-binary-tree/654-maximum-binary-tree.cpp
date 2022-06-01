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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return create(nums, 0, nums.size() -1);
    }
private: 
    TreeNode* create(vector<int> nums, int start, int end) {
        if(start > end) return NULL;
        
        int mx = -1, idx;
        for(int i=start; i<=end; i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                idx = i;
            }
        }
        
        TreeNode* root = new TreeNode(mx);
        root -> left = create(nums, start, idx -1);
        root -> right = create(nums, idx+1, end);
        
    return root;
    }
};