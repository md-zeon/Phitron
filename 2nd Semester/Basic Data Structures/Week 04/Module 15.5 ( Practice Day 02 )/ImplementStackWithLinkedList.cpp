/************************************************************
*  Problem: Implement Stack With Linked List
*  Link   : https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------
*
*  Problem Description:
*  Implement a stack data structure using a linked list. The 
*  stack should support the following operations:
*    1. push(x)   - Insert an element x on the top of the stack.
*    2. pop()     - Remove the element from the top of the stack.
*    3. getTop()  - Retrieve the top element without removing it.
*    4. getSize() - Return the number of elements in the stack.
*    5. isEmpty() - Check if the stack is empty.
* 
*  Approach:
*  - The stack will be implemented using a singly linked list. 
*  - Each node in the linked list will store the stack data and 
*    a pointer to the next node.
*  - For the push operation, a new node is created and added at 
*    the head of the linked list, making it the new top of the stack.
*  - For the pop operation, the head node is removed and the next 
*    node becomes the new head.
*  - getTop() returns the data of the head node.
*  - getSize() returns the count of nodes, and isEmpty() checks 
*    whether the list is empty by comparing the size to zero.
*  
*  Time Complexity :
*  - push()    : O(1)
*  - pop()     : O(1)
*  - getTop()  : O(1)
*  - getSize() : O(1)
*  - isEmpty() : O(1)
*  
*  Space Complexity: O(N) where N is the number of elements in the stack.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Node class represents an element in the stack (a single linked list node)
class Node
{
public:
    int data;    // The data stored in this node
    Node *next;  // Pointer to the next node

    // Default constructor
    Node()
    {
        this->data = 0;
        next = NULL;
    }

    // Constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Constructor with data and next pointer
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Stack class implemented using a linked list
class Stack
{
    Node* head;  // Pointer to the top of the stack (linked list head)
    int size;    // Number of elements in the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        head = NULL;  // Initially, the stack is empty
        size = 0;     // So the size is 0
    }

    // Get the number of elements in the stack
    int getSize()
    {
        return size;  // Simply return the size
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return size == 0;  // Stack is empty if size is 0
    }

    // Push an element onto the stack
    void push(int data)
    {
        Node* newNode = new Node(data);  // Create a new node with the data
        if(head == NULL) {
            head = newNode;  // If stack is empty, new node becomes the head
        } else {
            newNode->next = head;  // Otherwise, new node points to the current head
            head = newNode;        // And the new node becomes the new head
        }
        size++;  // Increment the size of the stack
    }

    // Pop the top element from the stack
    void pop()
    {
        if(head == NULL) {  // If the stack is empty, do nothing
            return;
        }
        Node* toDel = head;    // Store the current head (top element)
        head = head->next;     // Move the head to the next node
        toDel->next = NULL;    // Disconnect the node to be deleted
        delete toDel;          // Free the memory
        size--;  // Decrement the size of the stack
    }

    // Get the top element of the stack without removing it
    int getTop()
    {
        if(size == 0) return -1;  // If the stack is empty, return -1
        else return head->data;   // Otherwise, return the data of the head node
    }
};
