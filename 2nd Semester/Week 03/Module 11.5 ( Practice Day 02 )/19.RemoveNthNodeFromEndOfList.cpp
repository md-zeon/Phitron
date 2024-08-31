//* LEET CODE: 19. Remove Nth Node From End of List

//* LINK: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    int size(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return head;
        }
        if(head->next == nullptr && n == 1) {
            head = nullptr;
            return head;
        }

        if(size(head) - n == 0) {
            ListNode* toDel = head;
            head = head->next;
            delete toDel;
            return head;
        }

        ListNode* temp = head;
        for (int i = 1; i < size(head)-n; i++) {
            temp = temp->next;
        }
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head); // Dummy node to handle edge cases
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move first n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Delete the nth node
        ListNode* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};