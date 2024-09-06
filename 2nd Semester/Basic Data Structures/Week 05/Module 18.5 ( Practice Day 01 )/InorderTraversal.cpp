/************************************************************
*  Problem: Inorder Traversal
*  Link   : https://www.naukri.com/code360/problems/inorder-traversal_3839605?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Perform an inorder traversal of a binary tree. In inorder 
*  traversal, the nodes are visited in the following order:
*  1. Left subtree
*  2. Root node
*  3. Right subtree
*
*  Approach:
*  - Use recursion to traverse the left subtree first, then 
*    visit the root node, and finally traverse the right subtree.
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

/************************************************************

    Following is Binary Tree Node structure:

    class TreeNode {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) 
            : data(x), left(left), right(right) {}
    };

************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node class
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) 
        : data(x), left(left), right(right) {}
};

// Helper function for recursive inorder traversal
void inOrder(TreeNode* root, vector<int> &v) {
    if (root == NULL) return;
    inOrder(root->left, v);  // Traverse left subtree
    v.push_back(root->data); // Visit root node
    inOrder(root->right, v); // Traverse right subtree
}

// Function to get the inorder traversal of the binary tree
vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> result;
    inOrder(root, result);  // Perform recursive inorder traversal
    return result;          // Return the result
}
