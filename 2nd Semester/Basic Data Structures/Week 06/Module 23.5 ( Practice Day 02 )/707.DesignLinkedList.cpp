/************************************************************
*  Problem: 707. Design Linked List
*  Link   : https://leetcode.com/problems/design-linked-list/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-06
*  ----------------------------------------------
*
*  Problem Description:
*  - Design a linked list with the following operations:
*    - `get(index)`: Get the value of the index-th node in the linked list. If the index is invalid, return -1.
*    - `addAtHead(val)`: Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
*    - `addAtTail(val)`: Append a node of value val to the last element of the linked list.
*    - `addAtIndex(index, val)`: Add a node of value val before the index-th node in the linked list. If index equals the length of the list, the node will be appended to the end of the list. If index is greater than the length, the node will not be inserted.
*    - `deleteAtIndex(index)`: Delete the index-th node in the linked list if the index is valid.
*
*  Approach:
*  - Implement a doubly linked list to efficiently handle operations like insertion, deletion, and traversal in both directions.
*  - Keep track of the size of the linked list to handle boundary conditions.
*
*  Time Complexity : O(1) for add at head/tail operations, O(n) for traversal (e.g., get, delete, and add at a specific index).
*  Space Complexity: O(n) for storing n nodes.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Node class for the doubly linked list
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    // Constructor to initialize a node with a value
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// MyLinkedList class to implement the doubly linked list
class MyLinkedList {
    Node* head;  // Pointer to the head (first node) of the list
    Node* tail;  // Pointer to the tail (last node) of the list
    int size;    // Variable to track the size of the linked list

public:
    // Constructor to initialize an empty linked list
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Function to get the value of the index-th node
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* temp = head;
        while (index--) {
            temp = temp->next;
        }
        return temp->val;
    }

    // Function to add a node at the head of the list
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    // Function to add a node at the tail of the list
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Function to add a node at a specific index
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else if (index > size) {
            return;
        } else {
            Node* newNode = new Node(val);
            Node* temp = head;
            while (--index) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }

            temp->next = newNode;
            size++;
        }
    }

    // Function to delete a node at a specific index
    void deleteAtIndex(int index) {
        if (head == NULL) {
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                // The list is now empty
                tail = NULL;
            }
            delete temp;
        } else if (index == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            } else {
                // The list is now empty
                head = NULL;
            }
            delete temp;
        } else if (index < 0 || index >= size) {
            return;
        } else {
            Node* temp = head;
            while (--index) {
                temp = temp->next;
            }
            Node* toDel = temp->next;
            temp->next = toDel->next;
            toDel->next->prev = temp;
            delete toDel;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
