/************************************************************
*  Problem: Left View Of a Binary Tree
*  Link   : https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Given a binary tree, return the left view of the tree. 
*  The left view of a binary tree is the set of nodes visible when 
*  the tree is viewed from the left side.
*
*  Approach:
*  - Perform a level order traversal using a queue.
*  - Keep track of the first node at each level to form the left view.
*  - Use an auxiliary array `freq` to mark the first node visited at each level.
*  
*  Time Complexity : O(N)
*  - Each node is visited once, where N is the number of nodes in the tree.
*  
*  Space Complexity: O(W)
*  - The space complexity is O(W), where W is the maximum width of the tree 
*    (maximum number of nodes at any level).
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
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
************************************************************/

template <typename T>
class TreeNode {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};


vector<int> getLeftView(TreeNode<int> *root) {
    // Array to track whether we have already seen the first node at each level
    bool freq[3005] = {false};
    
    // Queue to perform level order traversal. Each element in the queue is a pair of (node, level).
    queue<pair<TreeNode<int>*, int>> q;

    // Initialize the result vector to store the left view of the tree.
    vector<int> v;

    // If the tree is not empty, start with the root node at level 1.
    if(root) q.push({root, 1});

    // Perform level order traversal
    while (!q.empty()) {
        // Get the front element (node and its level) from the queue.
        pair<TreeNode<int>*, int> pr = q.front();
        q.pop();
        
        TreeNode<int> *node = pr.first;  // Current node
        int level = pr.second;           // Current level

        // If this is the first node at this level, add it to the result vector.
        if(freq[level] == false) {
            v.push_back(node->data);
            freq[level] = true;  // Mark the level as visited.
        }

        // If the current node has a left child, add it to the queue with the next level.
        if(node->left) q.push({node->left, level + 1});

        // If the current node has a right child, add it to the queue with the next level.
        if(node->right) q.push({node->right, level + 1});
    }

    // Return the left view of the tree.
    return v;
}
