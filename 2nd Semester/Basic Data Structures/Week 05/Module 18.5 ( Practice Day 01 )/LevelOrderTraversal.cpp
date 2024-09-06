/************************************************************
*  Problem: Level Order Traversal
*  Link   : https://www.naukri.com/code360/problems/level-order-traversal_796002
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Perform a level order traversal of a binary tree. In a level 
*  order traversal, the nodes are visited level by level, from 
*  left to right at each level.
*
*  Approach:
*  - Use a queue to perform a breadth-first search (BFS) starting 
*    from the root. 
*  - Push the root node into the queue, then process each node by 
*    popping it from the front of the queue and adding its value 
*    to the result vector.
*  - Add the left and right children of the current node to the 
*    queue, if they exist.
*  
*  Time Complexity : O(N)
*  - Each node is visited exactly once, where N is the number of 
*    nodes in the binary tree.
*  
*  Space Complexity: O(N)
*  - The space complexity is O(N) due to the queue used for BFS.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/


#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the BinaryTreeNode class structure:

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

template <typename T>
class BinaryTreeNode {
    public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
};

// Function to perform level order traversal of the binary tree
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if(root == NULL) return v;  // If the tree is empty, return an empty vector

    queue<BinaryTreeNode<int>*> q;  // Queue to hold the nodes for BFS

    q.push(root);  // Start with the root node

    while (!q.empty()) {
        BinaryTreeNode<int> *f = q.front();
        q.pop();  // Process the front node
        v.push_back(f->val);  // Add the node's value to the result

        if(f->left) q.push(f->left);  // Add left child to the queue
        if(f->right) q.push(f->right);  // Add right child to the queue
    }

    return v;  // Return the vector containing level order traversal
}
