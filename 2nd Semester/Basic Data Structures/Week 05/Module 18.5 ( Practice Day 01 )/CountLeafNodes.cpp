/************************************************************
*  Problem: Count Leaf Nodes
*  Link   : https://www.naukri.com/code360/problems/count-leaf-nodes_893055
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Given a binary tree, count the number of leaf nodes. A leaf 
*  node is a node that does not have any children.
*
*  Approach:
*  - If the tree is empty (root is NULL), return 0 as there are 
*    no leaf nodes.
*  - If the node has no left or right child, it is a leaf node. 
*    Return 1.
*  - Otherwise, recursively count the leaf nodes in the left and 
*    right subtrees and return their sum.
*  
*  Time Complexity : O(N)
*  - We visit each node exactly once, where N is the number of 
*    nodes in the binary tree.
*  
*  Space Complexity: O(H)
*  - The space complexity is O(H), where H is the height of the 
*    binary tree, due to the recursive call stack.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
***********************************************************/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

// Function to count the number of leaf nodes in the binary tree
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // If the tree is empty, return 0
    if(root == NULL) {
        return 0;
    }

    // If the node is a leaf node, return 1
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recursively count the leaf nodes in the left and right subtrees
    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}
