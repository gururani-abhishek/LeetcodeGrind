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
class BSTIterator {
public:
    vector<int> ele;
    int ind = 0;
    BSTIterator(TreeNode* root) {
        inOrder(root);
        //for(auto u: ele) cout << u << " ";
    }
    
    int next() {
        return ele[ind++];
    }
    
    bool hasNext() {
        if(ind < ele.size()) return true;
        
        return false;
    }
    
private: 
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        inOrder(root -> left);
        
        ele.push_back(root -> val);
        
        inOrder(root -> right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */