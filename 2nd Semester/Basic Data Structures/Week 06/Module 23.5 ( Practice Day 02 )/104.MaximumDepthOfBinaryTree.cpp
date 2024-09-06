/************************************************************
*  Problem: 104. Maximum Depth of Binary Tree
*  Link   : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-06
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the root of a binary tree, return its maximum depth. 
*  - The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*
*  Approach:
*  - Use a recursive approach to calculate the depth of each subtree.
*  - The base case is when the node is null, where the depth is 0.
*  - For each non-null node, the depth is 1 plus the maximum depth of its left and right subtrees.
*
*  Time Complexity : O(n), where n is the number of nodes in the tree.
*  Space Complexity: O(h), where h is the height of the tree (due to recursion stack).
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
    // Function to calculate the maximum depth of the binary tree
    int maxDepth(TreeNode* root) {
        // Base case: If the node is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // The depth of the current node is 1 + max(leftDepth, rightDepth)
        return 1 + max(leftDepth, rightDepth);
    }
};
