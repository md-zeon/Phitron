/************************************************************
*  Problem: Node Level
*  Link   : https://www.naukri.com/code360/problems/node-level_920383?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Given a binary tree and a target value `searchedValue`, 
*  determine the level at which the node with that value exists. 
*  The root node is considered to be at level 1.
*
*  Approach:
*  - Perform a level order traversal using a queue.
*  - Store each node along with its corresponding level.
*  - As soon as the target node is found, return its level.
*  
*  Time Complexity : O(N)
*  - Each node is visited once, where N is the number of nodes 
*    in the tree.
*  
*  Space Complexity: O(W)
*  - The space complexity is O(W), where W is the maximum width 
*    of the tree (maximum number of nodes at any level).
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
************************************************************/

template <typename T>
class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
};

int nodeLevel(TreeNode<int>* root, int searchedValue) {
    // If the tree is empty, return 0 (indicating that the node is not found)
    if (root == NULL) return 0;

    // Create a queue to perform level order traversal
    // Each element in the queue is a pair consisting of the node and its corresponding level
    queue<pair<TreeNode<int>*, int>> q;

    // Start with the root node at level 1
    q.push({root, 1});

    // Perform level order traversal
    while (!q.empty()) {
        // Get the front node and its level from the queue
        pair<TreeNode<int>*, int> parent = q.front();
        TreeNode<int> *node = parent.first;  // Current node
        int level = parent.second;           // Current level
        q.pop();  // Remove the front element from the queue

        // Check if the current node's value matches the searched value
        if (node->val == searchedValue) {
            return level;  // Return the level if the node is found
        }

        // If the node has a left child, push it to the queue with the next level
        if (node->left) q.push({node->left, level + 1});
        // If the node has a right child, push it to the queue with the next level
        if (node->right) q.push({node->right, level + 1});
    }

    // If the searched value is not found in the tree, return 0
    return 0;
}
