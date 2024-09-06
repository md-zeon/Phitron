/************************************************************
*  Problem: 563. Binary Tree Tilt
*  Link   : https://leetcode.com/problems/binary-tree-tilt/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-04
*  ----------------------------------------------
*
*  Problem Description:
*  - Given a binary tree, return the tilt of the whole tree.
*  - The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values.
*  - The tilt of the whole tree is defined as the sum of all nodes' tilt.
*
*  Approach:
*  - Use a recursive function to calculate the sum of node values in each subtree.
*  - While doing this, compute the tilt of each node and add it to a global sum.
*  - The tilt of the root node will be the sum of the tilts of all the nodes in the tree.
*  
*  Time Complexity : O(n)
*  - We traverse each node of the tree once.
*  
*  Space Complexity: O(h)
*  - The space complexity is determined by the recursion stack depth, which is dependent on the height of the tree.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Definition of the TreeNode structure
struct TreeNode {
    int val;                    // Value of the node
    TreeNode *left;             // Pointer to the left child
    TreeNode *right;            // Pointer to the right child
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // Default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor with value
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  // Constructor with value and children
};

class Solution {
public:
    // Helper function to calculate tilt and sum of subtree values
    int tiltSum(TreeNode* node, int &sum) {
        // Base case: If the node is null, return 0
        if(node == nullptr) {
            return 0;
        }

        // Recursively calculate the sum of the left and right subtrees
        int l = tiltSum(node->left, sum);
        int r = tiltSum(node->right, sum);

        // Calculate the tilt of the current node and add it to the total sum
        sum += abs(l - r);

        // Return the sum of the current subtree (including the current node)
        return l + r + node->val;
    }

    // Main function to find the tilt of the entire tree
    int findTilt(TreeNode* root) {
        // If the root is null, the tilt is 0
        if(root == nullptr) {
            return 0;
        }

        int sum = 0;  // Initialize the total tilt sum
        tiltSum(root, sum);  // Calculate the tilt for the tree
        return sum;  // Return the total tilt
    }
};
