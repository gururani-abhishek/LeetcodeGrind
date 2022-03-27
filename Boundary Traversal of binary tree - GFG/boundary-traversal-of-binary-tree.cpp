// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector<int> ans;
    
    bool isNodeLeaf(Node* node) {
        if(node -> left == NULL && node -> right == NULL) 
            return true;
            
        return false;    
    }
    
    void addLeftNodes(Node* rootLeft) {
        Node* node = rootLeft;
        
        while(node != NULL) {
                if(!isNodeLeaf(node)) {
                    ans.push_back(node -> data);
                }
                
                if(node -> left != NULL) node = node -> left;
                else node = node -> right;
            
        }
        
    }
    
    void addRightNodes(Node* rootRight) {
        vector<int> temp;
        Node* node = rootRight;
        
        while(node != NULL) {
            if(!isNodeLeaf(node)) {
                temp.push_back(node -> data);
            }
            
            if(node -> right != NULL) node = node -> right;
            else node = node -> left;
        }
        
        for(auto u= temp.rbegin(); u != temp.rend(); u++) ans.push_back(*u);
        
    }
    
    //in order to reach the leaf nodes, I can do any type of traversal in which left and right come in succession, as I need to travel from anticlockwise.
    //preorder traversal
    
    void addLeafNodes(Node* node) {
        if(node == NULL) return;
        if(isNodeLeaf(node)) ans.push_back(node -> data);
        
        // triggering recursive traversal;
        addLeafNodes(node -> left);
        addLeafNodes(node -> right);
    }
    
    
    vector <int> boundary(Node *root)
    {
        
        if(root  == NULL) return ans;
        
        if(!isNodeLeaf(root)) ans.push_back(root -> data);
        
        addLeftNodes(root -> left);
        addLeafNodes(root);
        addRightNodes(root -> right);
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends