/************************************************************
*  Problem: 94. Binary Tree Inorder Traversal
*  Link   : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-06
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the root of a binary tree, return the inorder traversal of its nodes' values.
*
*  Approach:
*  - The inorder traversal visits nodes in the following order: left subtree, root node, right subtree.
*  - Implement a recursive function that will traverse the left subtree, record the root value, and then traverse the right subtree.
*
*  Time Complexity : O(n), where n is the number of nodes in the tree.
*  Space Complexity: O(n) for the recursive call stack in the worst case (unbalanced tree).
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function for inorder traversal
    void inOrder(TreeNode* root, vector<int> &v) {
        if (root == nullptr) {
            return;
        }

        // Traverse the left subtree
        inOrder(root->left, v);
        // Visit the root node
        v.push_back(root->val);
        // Traverse the right subtree
        inOrder(root->right, v);
    }

    // Main function to return inorder traversal as a vector
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);  // Start the inorder traversal
        return v;  // Return the result as a vector
    }
};
