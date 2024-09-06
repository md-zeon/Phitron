/************************************************************
*  Problem: Insert Into A Binary Search Tree
*  Link   : https://www.naukri.com/code360/problems/insert-into-a-binary-search-tree_1279913
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Insert a new value into an existing Binary Search Tree (BST) while maintaining the properties of a BST.
*
*  Approach:
*  - Recursively traverse the tree starting from the root.
*  - Compare the value to be inserted with the current node's value:
*    - If the value is smaller, move to the left child.
*    - If the value is larger, move to the right child.
*  - When a null child node is reached, insert the new value at that position.
*
*  Time Complexity : O(log n) on average (if the tree is balanced); O(n) in the worst case (if the tree is skewed).
*  Space Complexity: O(log n) due to recursion stack on average; O(n) in the worst case.
*  
*  Platform: Naukri Code360
*  Status  : Solved
************************************************************/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };

************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Definition of the TreeNode class template
template <typename T>
class TreeNode {
public:
    T val; // Value of the node
    TreeNode<T>* left, *right; // Left and right child pointers
    
    // Default constructor
    TreeNode() : val(0), left(NULL), right(NULL) {}

    // Constructor to initialize node with a value
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}

    // Constructor to initialize node with value, left, and right children
    TreeNode(T x, TreeNode<T>* left, TreeNode<T>* right) : val(x), left(left), right(right) {}
};

// Recursive function to insert a value into the BST
void insert(TreeNode<int>* &root, int val) {
    // Base case: If the current node is NULL, insert the value here
    if(root == NULL) {
        root = new TreeNode<int>(val); // Create a new node with the given value
        return;
    }

    // If the value to be inserted is less than the current node's value, go to the left subtree
    if(val < root->val) {
        if(root->left == NULL) {
            // If the left child is NULL, insert the value here
            root->left = new TreeNode<int>(val);
        } else {
            // Otherwise, recursively insert into the left subtree
            insert(root->left, val);
        }
    } 
    // If the value to be inserted is greater than or equal to the current node's value, go to the right subtree
    else {
        if(root->right == NULL) {
            // If the right child is NULL, insert the value here
            root->right = new TreeNode<int>(val);
        } else {
            // Otherwise, recursively insert into the right subtree
            insert(root->right, val);
        }
    }
}

// Function to handle the insertion in the BST and return the root node of the tree
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val) {
    // Call the recursive insert function
    insert(root, val);
    return root; // Return the root of the tree (unchanged)
}
