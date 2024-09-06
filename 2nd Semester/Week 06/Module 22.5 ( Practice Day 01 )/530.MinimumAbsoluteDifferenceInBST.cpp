/************************************************************
*  Problem: 530. Minimum Absolute Difference in BST
*  Link   : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given a Binary Search Tree (BST), find the minimum absolute difference between the values of any two nodes in the BST.
*  
*  Approach:
*  - The approach uses an in-order traversal of the BST to obtain the values in ascending order.
*  - As the values are traversed in sorted order, the minimum absolute difference is simply the smallest difference between consecutive nodes.
*  
*  Time Complexity : O(n)
*  - The time complexity is O(n) because each node is visited exactly once during the in-order traversal.
*
*  Space Complexity: O(h)
*  - The space complexity is O(h) where h is the height of the tree, which accounts for the recursion stack in the worst case.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    // Helper function to perform in-order traversal
    void inOrder(TreeNode* root, int &prev, int &minDiff) {
        // Base case: If the node is null, return
        if (root == nullptr) return;

        // Traverse the left subtree
        inOrder(root->left, prev, minDiff);

        // Compute the minimum difference between current node value and previous node value
        // `prev` is initialized to -1 to handle the first node case
        if (prev != -1) {
            minDiff = min(abs(root->val - prev), minDiff);
        }
        // Update `prev` to the current node's value
        prev = root->val;

        // Traverse the right subtree
        inOrder(root->right, prev, minDiff);
    }

    // Function to return the minimum absolute difference in BST
    int getMinimumDifference(TreeNode* root) {
        // Initialize `minDiff` to maximum integer value to find the minimum difference
        int minDiff = INT_MAX;
        // Initialize `prev` to -1, which will be updated to the value of each visited node
        int prev = -1;
        // Start the in-order traversal
        inOrder(root, prev, minDiff);
        // Return the minimum difference found
        return minDiff;
    }
};
