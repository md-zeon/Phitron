//* LEET CODE: 206. Reverse Linked List

//* LINK: https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};

class Solution2 {
public:
    void reverse(ListNode* &head, ListNode* curr) {
        if(curr->next == NULL) {
            head = curr;
            return;
        }

        reverse(head, curr->next);

        curr->next->next = curr;
        curr->next = NULL;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        reverse(head, head);

        return head;
    }
};