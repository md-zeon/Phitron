/************************************************************
*  Problem: 876. Middle of the Linked List
*  Link   : https://leetcode.com/problems/middle-of-the-linked-list/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-06
*  ----------------------------------------------
*
*  Problem Description:
*  - Given the head of a singly linked list, return the middle node of the list.
*  - If there are two middle nodes, return the second middle node.
*
*  Approach:
*  - Use the two-pointer technique to find the middle node.
*  - Maintain two pointers, `slow` and `fast`, both initially pointing to the head of the list.
*  - Move `fast` pointer two steps at a time and `slow` pointer one step at a time.
*  - When `fast` pointer reaches the end of the list, the `slow` pointer will be at the middle node.
*
*  Time Complexity : O(n) where n is the number of nodes in the linked list.
*  Space Complexity: O(1) as we are using constant extra space.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

// Definition of the ListNode structure
struct ListNode {
    int val; // Value of the node
    ListNode *next; // Pointer to the next node in the list

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor to initialize node with a value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor to initialize node with value and the next pointer
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to find the middle node of the linked list
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head; // Fast pointer that will move two steps at a time
        ListNode* slow = head; // Slow pointer that will move one step at a time

        // Traverse the list until the fast pointer reaches the end
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; // Move fast pointer two steps
            slow = slow->next; // Move slow pointer one step
        }

        // When the loop ends, slow pointer will be at the middle node
        return slow;
    }
};
