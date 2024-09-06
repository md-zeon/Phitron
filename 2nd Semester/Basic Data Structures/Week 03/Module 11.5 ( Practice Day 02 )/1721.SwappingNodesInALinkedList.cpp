//* LEET CODE: 1721. Swapping Nodes in a Linked List

//* LINK: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        ListNode* second = head;
        ListNode* temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }

        for (int i = 1; i <= size - k; i++) {
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};


class Solution2 {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;

        // Move first pointer to the k-th node
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Now, move the temp pointer to the k-th node and continue moving both temp and second pointers
        // until temp reaches the end. At that point, second will be at the k-th node from the end.
        temp = first;
        while (temp->next != nullptr) {
            temp = temp->next;
            second = second->next;
        }

        // Swap the values of the two nodes
        swap(first->val, second->val);

        return head;
    }
};