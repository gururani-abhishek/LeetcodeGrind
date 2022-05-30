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
        return makeMyTree(nums, 0, nums.size() -1);
    }
    
    
private: 
    TreeNode* makeMyTree(vector<int> nums, int start, int end) {
        if(start > end) {
            return NULL;
        }
        
        int idx = 0, mx = -1;
        for(int i=start; i<=end; i++) {
            if(nums[i] > mx) {
                idx = i;
                mx = nums[i];
            }
        }
        
        TreeNode* node = new TreeNode(mx);
        node -> left = makeMyTree(nums, start, idx -1);
        node -> right = makeMyTree(nums, idx + 1, end);
        
        return node;
    }
};