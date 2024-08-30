//* LEET CODE: 83. Remove Duplicates from Sorted List

//* LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode * temp = head;
        while (temp->next != NULL) {
            if(temp->val == temp->next->val) {
                ListNode * deleteNode = temp->next;
                temp->next = temp->next->next;
                delete deleteNode;
            }

            if(temp->next == NULL) {
                break;
            } else if(temp->val != temp->next->val) {
                temp = temp->next;
            }
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Skip the duplicate node
                current->next = current->next->next;
            } else {
                // Move to the next node if it's not a duplicate
                current = current->next;
            }
        }
        
        return head;
    }
};
