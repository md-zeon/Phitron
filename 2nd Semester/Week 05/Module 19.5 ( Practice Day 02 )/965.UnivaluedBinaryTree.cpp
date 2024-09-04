/************************************************************
*  Problem: 965. Univalued Binary Tree
*  Link   : https://leetcode.com/problems/univalued-binary-tree/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  A binary tree is univalued if every node in the tree has the same value. 
*  Return `true` if and only if the given tree is univalued.
*
*  Approach:
*  - Start by checking if the tree is empty (return `true`).
*  - Traverse the tree recursively, comparing the value of each node with the root's value.
*  - If all nodes have the same value, return `true`; otherwise, return `false`.
*  
*  Time Complexity : O(n)
*  - We visit each node once, where `n` is the number of nodes in the tree.
*  
*  Space Complexity: O(h)
*  - The space complexity depends on the height of the tree `h`, which is the depth of the recursive call stack.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Definition of the TreeNode structure
struct TreeNode {
    int val;                    // Value of the node
    TreeNode *left;             // Pointer to the left child
    TreeNode *right;            // Pointer to the right child
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // Default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor with value
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  // Constructor with value and children
};

// Solution class containing the function to solve the problem
class Solution {
public:
    // Helper function that checks if all nodes have the same value as `x`
    bool isSame(TreeNode* root, int x) {
        if(root == nullptr) return true;  // Base case: if the node is null, return true
        if(root->val != x) return false;  // If the node's value is not equal to `x`, return false

        // Recursively check the left and right subtrees
        bool l = isSame(root->left, x);
        bool r = isSame(root->right, x);

        // Return true only if both left and right subtrees have the same value
        return (l && r);
    } 

    // Function to check if the binary tree is univalued
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;  // If the tree is empty, it's univalued by definition

        int x = root->val;  // Get the value of the root node
        return isSame(root, x);  // Call the helper function to check if all nodes have the same value
    }
};
