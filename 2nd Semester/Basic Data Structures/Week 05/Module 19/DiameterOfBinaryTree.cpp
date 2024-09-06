/************************************************************
*  Problem: Diameter Of Binary Tree
*  Link   : https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Given a binary tree, find the diameter of the tree. The diameter
*  of a binary tree is the length of the longest path between any 
*  two nodes in the tree. This path may or may not pass through the root.
*
*  Approach:
*  - Perform a post-order traversal to calculate the height of the tree.
*  - While calculating the height, compute the diameter by taking the sum 
*    of the left and right heights at each node.
*  - Use a reference variable to keep track of the maximum diameter found.
*  
*  Time Complexity : O(N)
*  - Each node is visited once, where N is the number of nodes in the tree.
*  
*  Space Complexity: O(H)
*  - The space complexity is O(H), where H is the height of the tree 
*    (due to recursive call stack).
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the TreeNode class structure

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

// Helper function to calculate the height of the tree and update the diameter.
int maxHeight(TreeNode<int> *root, int &diameter) {
    // Base case: if the node is NULL, return height as 0.
    if (root == NULL) return 0;

    // Recursively calculate the height of the left subtree.
    int leftHeight = maxHeight(root->left, diameter);
    // Recursively calculate the height of the right subtree.
    int rightHeight = maxHeight(root->right, diameter);

    // The diameter at the current node is the sum of the heights of left and right subtrees.
    int currentDiameter = leftHeight + rightHeight;
    // Update the global diameter if the current diameter is larger than the previously recorded one.
    diameter = max(diameter, currentDiameter);

    // Return the height of the current node, which is 1 plus the maximum of left and right subtree heights.
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the diameter of the binary tree.
int diameterOfBinaryTree(TreeNode<int> *root) {
    int diameter = 0;  // Initialize the diameter as 0.
    maxHeight(root, diameter);  // Calculate the maximum height and update the diameter.
    
    return diameter;  // Return the final computed diameter.
}
