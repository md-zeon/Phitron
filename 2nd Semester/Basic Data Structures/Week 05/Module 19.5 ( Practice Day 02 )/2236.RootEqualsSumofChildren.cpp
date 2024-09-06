/************************************************************
*  Problem: 2236. Root Equals Sum of Children
*  Link   : https://leetcode.com/problems/root-equals-sum-of-children/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  You are given a binary tree where the root node has exactly two children. 
*  Return `true` if the value of the root node is equal to the sum of its children's values, 
*  and `false` otherwise.
*
*  Approach:
*  - Check if the sum of the left and right child nodes' values equals the root node's value.
*  - Return `true` if they are equal, otherwise return `false`.
*  
*  Time Complexity : O(1)
*  - The algorithm performs a constant number of operations (only two additions and a comparison).
*  
*  Space Complexity: O(1)
*  - The algorithm uses a constant amount of extra space.
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
    // Function to check if the root's value equals the sum of its children's values
    bool checkTree(TreeNode* root) {
        // Check if the sum of the left and right child's values equals the root's value
        if ((root->left->val) + (root->right->val) == root->val) {
            return true;  // Return true if the condition is met
        }
        return false;  // Otherwise, return false
    }
};


class Solution2 {
public:
    bool checkTree(TreeNode* root) {
        // Check if the sum of the left and right child nodes equals the root's value
        return (root->left->val + root->right->val == root->val);
    }
};