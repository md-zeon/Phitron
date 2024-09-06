/************************************************************
*  Problem: 100. Same Tree
*  Link   : https://leetcode.com/problems/same-tree/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-04
*  ----------------------------------------------
*
*  Problem Description:
*  - Given two binary trees, write a function to check if they are the same or not.
*  - Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
*
*  Approach:
*  - Use recursion to compare corresponding nodes of both trees.
*  - If both nodes are null, return true (base case for identical structure).
*  - If one of the nodes is null, return false (trees are not identical).
*  - Compare the values of both nodes. If equal, recursively check the left and right subtrees.
*  
*  Time Complexity : O(n)
*  - We traverse each node of the trees once.
*  
*  Space Complexity: O(h)
*  - The space complexity is determined by the recursion stack depth, which is dependent on the height of the trees.
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
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, the trees are identical at this point
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // If one node is null and the other is not, the trees are not identical
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // If the values of the nodes are equal, check their subtrees recursively
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        // If the values are different, the trees are not identical
        return false;
    }
};
