/************************************************************
*  Problem: 108. Convert Sorted Array to Binary Search Tree
*  Link   : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given an integer array `nums` where the elements are sorted in ascending order, convert it to a height-balanced binary search tree (BST).
*  
*  Approach:
*  - Use a recursive approach to convert the sorted array into a BST.
*  - Select the middle element of the array as the root of the BST to ensure balance.
*  - Recursively construct the left and right subtrees using the elements on the left and right of the middle element, respectively.
*  
*  Time Complexity : O(n)
*  - We traverse all the elements of the array exactly once to build the BST.
*  
*  Space Complexity: O(log n)
*  - The space complexity is determined by the recursion stack depth, which is O(log n) for a balanced tree.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

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
    // Helper function to recursively convert the array to a BST
    TreeNode* convert(vector<int> &arr, int si, int ei) {
        // Base case: if the start index is greater than the end index, return NULL
        if(si > ei) {
            return nullptr;
        }

        // Find the middle element to ensure a balanced BST
        int mid = si + (ei - si) / 2;

        // Create a new TreeNode with the middle element
        TreeNode* node = new TreeNode(arr[mid]);

        // Recursively construct the left and right subtrees
        node->left = convert(arr, si, mid - 1);
        node->right = convert(arr, mid + 1, ei);

        // Return the root of the constructed subtree
        return node;
    }

    // Main function to convert the sorted array to a BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the helper function with the entire array
        return convert(nums, 0, nums.size() - 1);
    }
};
