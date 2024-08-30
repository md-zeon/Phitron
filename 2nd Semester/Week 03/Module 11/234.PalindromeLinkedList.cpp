//* LEET CODE: 234. Palindrome Linked List

//* LINK: https://leetcode.com/problems/palindrome-linked-list/description/

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
    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
        ListNode * newNode = new ListNode(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void reverse(ListNode* &head, ListNode * node) {
        if(node->next == NULL) {
            head = node;
            return;
        }

        reverse(head, node->next);
        node->next->next = node;
        node->next = NULL;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * newHead = NULL;
        ListNode * newTail = NULL;
        ListNode * temp = head;

        while(temp != NULL) {
            insertAtTail(newHead, newTail, temp->val);
            temp = temp->next;
        }

        reverse(newHead, newHead);

        temp = head;
        ListNode* temp2 = newHead;
        while (temp != NULL) {
            if(temp->val != temp2->val) {
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
};

class Solution2 {
public:
    ListNode * reverse(ListNode * head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode * curr = head;
        ListNode * prev = NULL;
        while(curr != NULL) {
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }

    bool isPalindrome(ListNode * head) {
        ListNode * slow = head, * fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * midStart = reverse(slow);

        ListNode * temp = head;
        ListNode * temp2 = midStart;

        while (temp2 != NULL) {
            if(temp->val != temp2->val) {
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
};