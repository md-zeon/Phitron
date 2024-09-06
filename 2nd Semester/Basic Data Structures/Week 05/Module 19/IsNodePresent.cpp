/************************************************************
*  Problem: Is Node Present?
*  Link   : https://www.naukri.com/code360/problems/code-find-a-node_5682
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Given a binary tree and an integer `x`, determine if the value
*  `x` is present in the tree. Return `true` if the node with
*  value `x` exists, otherwise return `false`.
*
*  Approach 1 (Iterative - Level Order Traversal):
*  - Perform a level order traversal using a queue.
*  - Check if any node's value matches `x`.
*  - If found, return `true`; otherwise, continue searching.
*  
*  Time Complexity : O(N)
*  - Each node is visited once, where N is the number of nodes 
*    in the tree.
*  
*  Space Complexity: O(W)
*  - The space complexity is O(W), where W is the maximum width 
*    of the tree (maximum number of nodes at any level).
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/


/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <bits/stdc++.h>
using namespace std;


template <typename T>
class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

// Approach 1: Iterative - Level Order Traversal
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // If the tree is empty, return false
    if (root == NULL) return false;

    // Create a queue for level order traversal
    queue<BinaryTreeNode<int>*> q;
    // Start by adding the root to the queue
    q.push(root);

    // Perform level order traversal until the queue is empty
    while (!q.empty()) {
        // Get the front node from the queue
        BinaryTreeNode<int> *node = q.front();
        // Remove the node from the queue
        q.pop();
        
        // Check if the current node's data is equal to x
        if (node->data == x) return true;

        // If the current node has a left child, add it to the queue
        if (node->left) q.push(node->left);
        // If the current node has a right child, add it to the queue
        if (node->right) q.push(node->right);
    }

    // If x is not found in the tree, return false
    return false;
}


/************************************************************
*  Problem: Is Node Present?
*  Link   : https://www.naukri.com/code360/problems/code-find-a-node_5682
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Approach 2 (Recursive):
*  - Perform a recursive search on the tree.
*  - If the current node's value matches `x`, return `true`.
*  - Otherwise, recursively check the left and right subtrees.
*  
*  Time Complexity : O(N)
*  - Each node is visited once, where N is the number of nodes 
*    in the tree.
*  
*  Space Complexity: O(H)
*  - The space complexity is O(H), where H is the height of the 
*    tree due to the recursive call stack.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

// Approach 2: Recursive
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // If the tree is empty, return false
    if (root == NULL) return false;

    // If the current node's data matches x, return true
    if (root->data == x) return true;

    // Recursively search the left subtree
    bool leftCheck = isNodePresent(root->left, x);
    // Recursively search the right subtree
    bool rightCheck = isNodePresent(root->right, x);

    // Return true if x is found in either the left or right subtree
    return leftCheck || rightCheck;
}
