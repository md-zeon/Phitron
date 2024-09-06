/************************************************************
*  Problem: Postorder Traversal (Recursive)
*  Link   : https://www.naukri.com/code360/problems/name_2035933
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Perform a postorder traversal of a binary tree. In postorder 
*  traversal, the nodes are recursively visited in this order:
*  1. Left subtree
*  2. Right subtree
*  3. Root node
*
*  Approach:
*  - Use recursion to visit the left and right subtrees first,
*    and then visit the root node.
*  - Collect the nodes' values in a vector during the traversal.
*  
*  Time Complexity : O(N)
*  - We visit each node exactly once, where N is the number of 
*    nodes in the binary tree.
*  
*  Space Complexity: O(N)
*  - The recursive approach has a space complexity of O(N) due to 
*    the call stack in the worst case (skewed tree).
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Recursive approach for postorder traversal
vector<int> v;

void postOrder(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->left);    // Visit left subtree
    postOrder(root->right);   // Visit right subtree
    v.push_back(root->data);  // Visit root
}

vector<int> postorderTraversal(TreeNode *root) {
    v.clear();               // Clear the vector before use
    postOrder(root);         // Perform recursive postorder traversal
    return v;                // Return the result
}

/************************************************************
*  Problem: Postorder Traversal (Iterative)
*  Link   : https://www.naukri.com/code360/problems/name_2035933
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Perform a postorder traversal of a binary tree using an 
*  iterative approach. In postorder traversal, the nodes are 
*  visited in this order:
*  1. Left subtree
*  2. Right subtree
*  3. Root node
*
*  Approach:
*  - Use two stacks to simulate postorder traversal. The first 
*    stack is used for traversing, and the second stack is used 
*    to store nodes in reverse postorder order.
*  - Finally, pop nodes from the second stack to get the result.
*  
*  Time Complexity : O(N)
*  - We visit each node exactly once, where N is the number of 
*    nodes in the binary tree.
*  
*  Space Complexity: O(N)
*  - The iterative approach uses O(N) space to store nodes in the 
*    two stacks.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

vector<int> postorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;
    
    stack<TreeNode*> s1, s2;
    s1.push(root);
    
    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);
        
        if (node->left) s1.push(node->left);   // Push left child
        if (node->right) s1.push(node->right); // Push right child
    }
    
    while (!s2.empty()) {
        result.push_back(s2.top()->data); // Collect nodes in postorder
        s2.pop();
    }
    
    return result;
}
