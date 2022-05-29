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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root -> val == p -> val || root -> val == q -> val) {
            return root;
        }
        
        TreeNode* l = lowestCommonAncestor(root -> left, p, q);
        TreeNode* r = lowestCommonAncestor(root -> right, p, q);

        if(l == NULL) return r;
        else if(r == NULL) return l;
        
    return root;
        
    }
};


//l r returned
//n nN -> nN(r);
//n n -> n(l/r);
//nN nN -> root
//nN n -> nN(l);


//         3
//        /  \
//       5    1
//      / \  / \
//     6  2  0  8
//       / \
//      7    4
        
            
            
            
//             5 -> l = 6 , r = 2
//             3 -> l = 5 , r = null
            
//             3 -> l = 5 , r = null
//             5 
            
            
            
            
            
//             5
//          NULL   2 returned -> 2 
         
//             1
//          NULL    8 returned -> 8
        
//             3
//         2 returned 8 returned -> root;
        