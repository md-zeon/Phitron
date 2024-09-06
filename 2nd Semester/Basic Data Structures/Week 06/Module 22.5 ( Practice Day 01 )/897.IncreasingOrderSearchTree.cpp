/************************************************************
*  Problem: 897. Increasing Order Search Tree
*  Link   : https://leetcode.com/problems/increasing-order-search-tree/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the root of a binary search tree (BST), rearrange the tree in in-order so that the left child of every node is null and the right child is the next node in the in-order traversal.
*  
*  Approach:
*  - Perform an in-order traversal of the BST to retrieve the node values in sorted order.
*  - Create a new tree where every node only has a right child, corresponding to the values in increasing order.
*  
*  Time Complexity : O(n)
*  - Each node is visited once during in-order traversal, and a new tree with the same number of nodes is built.
*
*  Space Complexity: O(n)
*  - The space complexity is O(n) for storing the values in the vector and for the recursion stack during in-order traversal.
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

class Solution {
public:
    // Helper function to perform in-order traversal
    void inOrder(TreeNode* root, vector<int> &v) {
        // Base case: If the node is null, return
        if (root == nullptr) return;

        // Traverse the left subtree
        inOrder(root->left, v);
        // Add the current node's value to the vector
        v.push_back(root->val);
        // Traverse the right subtree
        inOrder(root->right, v);
    }

    // Function to create the increasing order search tree
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v; // Vector to store the values in in-order
        inOrder(root, v); // Populate the vector with in-order traversal of the tree
        
        // Create a new tree with the first value from the vector
        TreeNode* node = new TreeNode(v[0]);
        TreeNode* temp = node; // Temporary pointer to build the tree
        
        // Iterate through the vector and build the tree with right children only
        for (int i = 1; i < v.size(); i++) {
            // Create a new node with the current value and set it as the right child of temp
            temp->right = new TreeNode(v[i]);
            // Move the temp pointer to the newly created right child
            temp = temp->right;
        }
        // Return the root of the newly created tree
        return node;
    }
};



/************************************************************
*  Problem: 897. Increasing Order Search Tree
*  Link   : https://leetcode.com/problems/increasing-order-search-tree/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------

*  Problem Description:
*  Given the root of a binary search tree, rearrange the tree 
*  in in-order so that the leftmost node in the tree is now 
*  the root of the tree, and every node has no left child and 
*  only one right child.

*  Approach:
*  - We perform an in-order traversal to visit nodes in sorted order.
*  - We use a dummy node to facilitate the reconstruction of the tree.
*  - For each node visited, we set its left child to nullptr and 
*    attach it to the right of the previously visited node.
*  - This ensures that all nodes are rearranged in increasing order 
*    with only right children.

*  Time Complexity : O(N), where N is the number of nodes in the tree.
*  Space Complexity: O(H), where H is the height of the tree, 
*                    due to recursion stack in in-order traversal.

*  Platform: LeetCode
*  Status  : Solved
************************************************************/



class Solution2 {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyNode = new TreeNode(0);  // Step 1: Create a dummy node
        TreeNode* current = dummyNode;  // Pointer to keep track of the last node in the new tree
        
        inorder(root, current);  // Step 2: Perform inorder traversal and rearrange nodes
        
        return dummyNode->right;  // Step 3: Return the right child of the dummy node (new root)
    }
    
private:
    void inorder(TreeNode* node, TreeNode*& current) {
        if (node == nullptr) return;  // Base case: if the node is null, just return
        
        // Traverse the left subtree
        inorder(node->left, current);
        
        // Process the current node
        node->left = nullptr;  // Set the left child of the current node to null
        current->right = node;  // Attach the current node to the right of the last node in the new tree
        current = node;  // Move the current pointer to this node
        
        // Traverse the right subtree
        inorder(node->right, current);
    }
};
