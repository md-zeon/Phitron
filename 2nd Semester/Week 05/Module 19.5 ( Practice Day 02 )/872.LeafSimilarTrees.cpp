/************************************************************
*  Problem: 872. Leaf-Similar Trees
*  Link   : https://leetcode.com/problems/leaf-similar-trees/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-04
*  ----------------------------------------------
*
*  Problem Description:
*  - Two binary trees are considered leaf-similar if their leaf value sequence is the same.
*  - The leaf value sequence is the sequence of values of the leaf nodes read from left to right.
*  - Given two binary trees, return `true` if they are leaf-similar, otherwise return `false`.
*
*  Approach:
*  - Traverse both trees and collect the values of the leaf nodes in two separate vectors.
*  - Compare the two vectors to check if the leaf sequences are identical.
*  
*  Time Complexity : O(n + m)
*  - We traverse both trees where `n` and `m` are the number of nodes in the two trees.
*  
*  Space Complexity: O(h1 + h2)
*  - The space complexity is determined by the recursion stack depth, which is dependent on the height of the trees `h1` and `h2`.
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
    // Helper function to collect the leaf values of a binary tree
    void leafSequence(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;  // Base case: if the node is null, return
        
        // If the node is a leaf node, add its value to the vector
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(root->val);
        }

        // Recursively traverse the left and right subtrees
        leafSequence(root->left, v);
        leafSequence(root->right, v);
    }

    // Function to check if two binary trees are leaf-similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;  // Vectors to store the leaf sequences of both trees
        
        // Collect the leaf sequences for both trees
        leafSequence(root1, v1);
        leafSequence(root2, v2);

        // Compare the two leaf sequences
        return v1 == v2;   
    }
};
