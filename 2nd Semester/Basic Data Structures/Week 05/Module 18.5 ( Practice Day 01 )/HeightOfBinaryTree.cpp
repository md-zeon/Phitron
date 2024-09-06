/************************************************************
*  Problem: Height of Binary Tree
*  Link   : https://www.naukri.com/code360/problems/tree-height_4609628?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Given a binary tree, calculate its height. The height of a 
*  binary tree is defined as the number of edges in the longest 
*  path from the root to a leaf node.
*
*  Approach:
*  - Use recursion to calculate the height of the binary tree.
*  - The height of the tree is the maximum height of its left 
*    and right subtrees, plus one for the root.
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


#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

template <typename T>
class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
};

// Helper function to calculate the height of the binary tree
int height(TreeNode<int> *root) {
    if(root == NULL) return 0; // Base case: an empty tree has height 0
    int leftHeight = height(root->left);  // Calculate height of left subtree
    int rightHeight = height(root->right);  // Calculate height of right subtree
    return max(leftHeight, rightHeight) + 1; // Height is the max of both subtrees + 1 (for root)
}

// Function to calculate the height of a binary tree
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    return height(root);  // Call the helper function
}
