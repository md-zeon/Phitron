/************************************************************
*  Problem: Preorder Binary Tree
*  Link   : https://www.naukri.com/code360/problems/preorder-binary-tree_5948?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Perform a preorder traversal of a binary tree. In preorder 
*  traversal, the nodes are recursively visited in this order:
*  1. Root node
*  2. Left subtree
*  3. Right subtree
*
*  Approach:
*  - Use recursion to visit the root node first, then recursively 
*    traverse the left and right subtrees.
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

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

// Recursive helper function for preorder traversal
void pre_order(TreeNode<int>* root, vector<int> &v) {
    if(root == NULL) return;
    v.push_back(root->data);   // Visit root node
    pre_order(root->left, v);  // Traverse left subtree
    pre_order(root->right, v); // Traverse right subtree
}

// Function to return the preorder traversal of the binary tree
vector<int> preOrder(TreeNode<int> * root) {
    vector<int> v;
    pre_order(root, v); // Perform recursive preorder traversal
    return v;           // Return the result
}
