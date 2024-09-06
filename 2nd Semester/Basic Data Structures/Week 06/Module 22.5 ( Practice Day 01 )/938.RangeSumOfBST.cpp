/************************************************************
*  Problem: 938. Range Sum of BST
*  Link   : https://leetcode.com/problems/range-sum-of-bst/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the root of a binary search tree and two integers `low` and `high`, return the sum of values of all nodes with a value in the range [low, high].
*
*  Approach:
*  [Description of the approach used in each solution]
*  
*  Time Complexity : [O(n)]
*  - Each node is processed once.
*  
*  Space Complexity: [O(h)]
*  - The space complexity is determined by the depth of the recursion stack or the size of the stack/queue.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return 0;
        }

        // If current node's value is within the range, include it in the sum
        if(root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        // If current node's value is less than low, skip the left subtree
        if(root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        // If current node's value is greater than high, skip the right subtree
        if(root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        return 0;
    }
};

/************************************************************
*  Problem: 938. Range Sum of BST
*  Link   : https://leetcode.com/problems/range-sum-of-bst/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the root of a binary search tree and two integers `low` and `high`, return the sum of values of all nodes with a value in the range [low, high].
*
*  Approach:
*  - Use an iterative approach with a stack to perform a depth-first traversal.
*  - For each node, check if its value is within the range and accumulate the sum if it is.
*  - Push the left and right children to the stack based on the node's value and the range:
*    - If the current node's value is less than `low`, push only the right child.
*    - If the current node's value is greater than `high`, push only the left child.
*  
*  Time Complexity : [O(n)]
*  - Each node is processed once.
*  
*  Space Complexity: [O(h)]
*  - The space complexity is determined by the maximum size of the stack, which is O(h) where h is the height of the tree.
*
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

class Solution2 {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(node != nullptr) {
                // If the current node's value is within the range, add it to the sum
                if(node->val >= low && node->val <= high) {
                    sum += node->val;
                }

                // Push left and right children to the stack as needed
                if(low < node->val) {
                    st.push(node->left);
                }

                if(high > node->val) {
                    st.push(node->right);
                }
            }
        }
        return sum;
    }
};

/************************************************************
*  Problem: 938. Range Sum of BST
*  Link   : https://leetcode.com/problems/range-sum-of-bst/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the root of a binary search tree and two integers `low` and `high`, return the sum of values of all nodes with a value in the range [low, high].
*
*  Approach:
*  - Use an iterative approach with a queue to perform a breadth-first traversal.
*  - For each node, check if its value is within the range and accumulate the sum if it is.
*  - Enqueue the left and right children based on the node’s value and the range:
*    - If the current node's value is less than `low`, enqueue only the right child.
*    - If the current node's value is greater than `high`, enqueue only the left child.
*  
*  Time Complexity : [O(n)]
*  - Each node is processed once.
*  
*  Space Complexity: [O(w)]
*  - The space complexity is determined by the maximum size of the queue, which is O(w) where w is the maximum width of the tree.
*
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

class Solution3 {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node != nullptr) {
                // If the current node's value is within the range, add it to the sum
                if(node->val >= low && node->val <= high) {
                    sum += node->val;
                }

                // Enqueue left and right children as needed
                if(low < node->val) {
                    q.push(node->left);
                }

                if(high > node->val) {
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};
