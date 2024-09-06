/************************************************************
*  Problem: 700. Search in a Binary Search Tree
*  Link   : https://leetcode.com/problems/search-in-a-binary-search-tree/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - You are given the root of a binary search tree (BST) and an integer `val`.
*    Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node.
*    If such a node does not exist, return `nullptr`.
*
*  Approach:
*  - The binary search tree property allows us to determine whether to go left or right:
*    - If the value we're looking for is less than the current node's value, move to the left subtree.
*    - If the value is greater, move to the right subtree.
*    - If the value equals the current node's value, return the current node.
*  - We can solve this recursively or iteratively.
*  
*  Time Complexity : O(h)
*  - The time complexity is proportional to the height of the tree (h).
*  - In the worst case, h = O(n) for a skewed tree, and in the best case, h = O(log n) for a balanced tree.
*  
*  Space Complexity: O(h)
*  - The space complexity is determined by the recursion stack, which is proportional to the height of the tree (h).
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

// Recursive Approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if the node is null or we've found the value
        if(root == nullptr || root->val == val) return root;

        // If the value is greater, search in the right subtree
        if(root->val < val) {
            return searchBST(root->right, val);
        } 
        // If the value is smaller, search in the left subtree
        else {
            return searchBST(root->left, val);
        }
    }
};

// Iterative Approach (Optional)
class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr && root->val != val) {
            if(val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};
