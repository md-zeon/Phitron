/************************************************************
*  Problem: Special Binary Tree
*  Link   : https://www.naukri.com/code360/problems/special-binary-tree_920502?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  A binary tree is called a special binary tree if every non-leaf node has exactly two children. 
*  Your task is to determine if the given binary tree is a special binary tree.
*
*  Approach:
*  - Perform a recursive check on each node.
*  - If a node is a leaf node, it is valid for the special binary tree.
*  - If a node has only one child, then it does not satisfy the conditions for a special binary tree.
*  - Recursively check the left and right subtrees to ensure all nodes meet the conditions.
*  
*  Time Complexity : O(N)
*  - The algorithm traverses all nodes in the binary tree exactly once.
*  
*  Space Complexity: O(H)
*  - The space complexity is O(H), where H is the height of the tree (due to recursive call stack).
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode {
        public:
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;

            BinaryTreeNode(T data) {
                this->data = data;
                left = NULL;
                right = NULL;
            }
    };

*************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Definition of BinaryTreeNode class.
template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

// Function to check if the binary tree is a special binary tree.
bool isSpecialBinaryTree(BinaryTreeNode<int>* root) {
    // If the node is a leaf node (no children), it satisfies the condition.
    if (root->left == NULL && root->right == NULL) return true;
    
    // If the node has exactly one child, it does not satisfy the condition.
    if (root->left == NULL || root->right == NULL) return false;

    // Recursively check the left and right subtrees.
    bool leftCheck = isSpecialBinaryTree(root->left);
    bool rightCheck = isSpecialBinaryTree(root->right);

    // If either the left or right subtree fails, return false.
    if (!leftCheck || !rightCheck) return false;

    // If both the left and right subtrees are valid, return true.
    return true;
}
