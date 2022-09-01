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
    // one issue that I was having : 
    // how to remove a node while I'm backtracking from that path?? 
    // so I was keenly thinking of datastructures like heap, set...blah blah
    // but I forgot the basics of recursion, when I backtrack, the state resets to the
    // previous state and all the variables revert back, hence maxTillNow will revert back on
    // it's previous state.
    
    int goodNodes(TreeNode* root) {
        // maxTillNow will hold the max element till this particular node 
        // I want it to intially be : INT_MIN, so that the first node gets picked as
        // a good node.
        
        int maxTillNow = INT_MIN, ans = 0; // ans will be the counter of all good nodes till now
        preOrder(root, maxTillNow, ans);
        return ans; // return the counter of good elements
    }
    
private: 
    void preOrder(TreeNode* root, int maxTillNow, int &ans) {
        if(root == nullptr) return;
        
        // if current node val is the greatest node val till now, 
        if(root -> val >= maxTillNow) {
            ans++; // count it as good node
            maxTillNow = root -> val; // update your max
        }
        
        preOrder(root -> left, maxTillNow, ans); // go to the left
        preOrder(root -> right, maxTillNow, ans); // go to the right
        
        // when it'll backtrack, maxTillNow will be reverted on it's own
    }
};

// IN THE PATH FROM ROOT TO X, WE'VE GOT NO NODES WITH VALUE GREATER THAN X
// RETURN NUMBER OF GOOD NODES IN THE BTREE

// nodes with greatest value from the root to them(path)
// root will always be a good node

//       3
//    1     4
// 3     1     5

// preorder type traversal 