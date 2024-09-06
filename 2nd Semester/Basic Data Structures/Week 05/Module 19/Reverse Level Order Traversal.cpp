/************************************************************
*  Problem: Reverse Level Order Traversal
*  Link   : https://www.naukri.com/code360/problems/reverse-level-order-traversal_764339?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Perform a reverse level order traversal of a binary tree. In reverse level order traversal, the nodes are visited level by level from bottom to top, and within each level, nodes are visited from left to right.
*
*  Approach:
*  - Perform a normal level order traversal using a queue.
*  - Store the nodes in a vector as they are visited.
*  - After the traversal is complete, reverse the vector to get the reverse level order.
*  
*  Time Complexity : O(N)
*  - The algorithm traverses all nodes in the binary tree exactly once.
*  
*  Space Complexity: O(N)
*  - The space complexity is O(N) for storing the nodes in the vector and queue.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

/************************************************************
    Following is the TreeNode class structure:

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

#include <bits/stdc++.h>
using namespace std;

// Definition of the TreeNode class.
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

// Function to perform reverse level order traversal of a binary tree.
vector<int> reverseLevelOrder(TreeNode<int> *root) {
    // Vector to store the result.
    vector<int> result;

    // Queue to perform level order traversal.
    queue<TreeNode<int> *> q;

    // If root is not null, push it to the queue.
    if (root) q.push(root);

    // Loop until the queue is empty.
    while (!q.empty()) {
        // Get the front node from the queue.
        TreeNode<int> *currentNode = q.front();
        q.pop();

        // Add the node's value to the result vector.
        result.push_back(currentNode->val);

        // Push the left child to the queue if it exists.
        if (currentNode->left) q.push(currentNode->left);

        // Push the right child to the queue if it exists.
        if (currentNode->right) q.push(currentNode->right);
    }

    // Reverse the result vector to get the reverse level order traversal.
    reverse(result.begin(), result.end());

    // Return the final result.
    return result;
}


vector<int> reverseLevelOrder2(TreeNode<int> *root) {
    // vector to store the result
    vector<int> result;
    // vector to store the level order traversal
    if (root == NULL) return result;
    // queue to perform level order traversal
    queue<TreeNode<int>*> q;
    // push the root node to the queue
    q.push(root);
    // stack to store the nodes
    stack<int> s;
    // loop until the queue is empty
    while (!q.empty()) {
        // get the front node from the queue
        TreeNode<int>* node = q.front();
        // pop the node from the queue
        q.pop();
        // push the node's value to the stack
        s.push(node->val);
        // push the left and right child to the queue
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    // loop until the stack is empty
    while (!s.empty()) {
        // push the top node's value to the result vector
        result.push_back(s.top());
        // pop the node from the stack
        s.pop();
    }
    
    // return the final result
    return result;
}
