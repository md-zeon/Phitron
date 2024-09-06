//* LEET CODE: 203. Remove Linked List Elements

//* LINK: https://leetcode.com/problems/remove-linked-list-elements/description/

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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
        
        return head;
    }
};


class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return head;
        }
        ListNode * prevHead = new ListNode(0);
        prevHead->next = head;
        ListNode * temp = prevHead;
        while (temp->next != NULL) {
            if(temp->next->val == val) {
                ListNode * toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
        ListNode * newHead = prevHead->next;
        delete prevHead;
        return newHead;
    }
};
