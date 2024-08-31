//* LEET CODE: 2181. Merge Nodes in Between Zeros

//* LINK: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* newHead = nullptr;
        ListNode* newTemp = nullptr;
        int sum = 0;

        while (temp->next != nullptr) {
            sum += temp->val;
            if(temp->next->val == 0) {
                ListNode *newNode = new ListNode(sum);
                if(newTemp == nullptr) {
                    newHead = newNode;
                    newTemp = newHead;
                } else {
                    newTemp->next = newNode;
                    newTemp = newTemp->next;
                }
                sum = 0;
            }
            temp = temp->next;
        }
        return newHead;
    }
};