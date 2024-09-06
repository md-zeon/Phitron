/************************************************************
*  Problem: Left Sum
*  Link   : https://www.naukri.com/code360/problems/left-sum_920380?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-03
*  ----------------------------------------------
*
*  Problem Description:
*  Given a binary tree, calculate the sum of all nodes that are 
*  the left child of their respective parents.
*
*  Approach:
*  - Use recursion to traverse the binary tree.
*  - If the current node has a left child, add its value to the 
*    result.
*  - Recursively calculate the left sum for the left and right 
*    subtrees and return their sum.
*  
*  Time Complexity : O(N)
*  - We visit each node exactly once, where N is the number of 
*    nodes in the binary tree.
*  
*  Space Complexity: O(H)
*  - The space complexity is O(H), where H is the height of the 
*    binary tree, due to the recursive call stack.
*  
*  Platform: [Platform Name]
*  Status  : Solved
************************************************************/


/*
	Tree Node class.

	class BinaryTreeNode 
	{
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
	}
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

// Function to calculate the sum of left child nodes in the binary tree
long long leftSum(BinaryTreeNode<int> *root)
{
	// Base case: If the tree is empty, return 0
	if(root == NULL) {
		return 0;
	}
	
	// If the current node has a left child, add its value to the result
	long long sum = 0;
	if(root->left) {
		sum += root->left->data;
	}
	
	// Recursively calculate the left sum for the left and right subtrees
	return sum + leftSum(root->left) + leftSum(root->right);
}
