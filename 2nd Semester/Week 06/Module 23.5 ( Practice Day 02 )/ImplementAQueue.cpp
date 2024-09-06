/************************************************************
*  Problem: Implement a Queue
*  Link   : https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------
*
*  Problem Description:
*  Implement a queue data structure using a singly linked list. 
*  The queue should support the following operations:
*    1. enqueue(x) - Insert an element x at the end of the queue.
*    2. dequeue()  - Remove the front element from the queue.
*    3. front()    - Retrieve the front element without removing it.
*    4. isEmpty()  - Check if the queue is empty.
*
*  Approach:
*  - The queue will be implemented using a singly linked list. 
*  - The `head` pointer will point to the front of the queue, and 
*    the `tail` pointer will point to the rear of the queue.
*  - For the `enqueue()` operation, a new node is added to the end 
*    of the list (tail), and the tail pointer is updated.
*  - For the `dequeue()` operation, the head node is removed, and 
*    the head pointer is updated to the next node.
*  - The `front()` function returns the data of the head node.
*  
*  Time Complexity :
*  - enqueue() : O(1)
*  - dequeue() : O(1)
*  - front()   : O(1)
*  - isEmpty() : O(1)
*  
*  Space Complexity: O(N), where N is the number of elements in the queue.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Node class represents an element in the queue (a single linked list node)
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

// Queue class implemented using a linked list
class Queue {
    Node* head;  // Pointer to the front of the queue (linked list head)
    Node* tail;  // Pointer to the rear of the queue (linked list tail)
    int size;    // Number of elements in the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        head = tail = NULL;  // Initially, both head and tail are NULL
        size = 0;            // Queue is empty, so size is 0
    }

    /*----------------- Public Functions of Queue -----------------*/

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;  // Queue is empty if size is 0
    }

    // Enqueue (add) an element to the rear of the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);  // Create a new node with the given data
        if(head == NULL) {
            head = newNode;  // If queue is empty, both head and tail point to the new node
            tail = newNode;
        } else {
            tail->next = newNode;  // Otherwise, the current tail points to the new node
            tail = newNode;        // And the new node becomes the new tail
        }
        size++;  // Increment the size of the queue
    }

    // Dequeue (remove) the front element from the queue
    int dequeue() {
        if(isEmpty()) return -1;  // If queue is empty, return -1
        Node* toDel = head;       // Store the current head (front element)
        int ele = toDel->data;    // Store the data of the front element
        head = head->next;        // Move the head pointer to the next node
        toDel->next = NULL;       // Disconnect the node to be deleted
        delete toDel;             // Free the memory
        size--;  // Decrement the size of the queue
        return ele;  // Return the dequeued element
    }

    // Get the front element of the queue without removing it
    int front() {
        if(isEmpty()) return -1;  // If queue is empty, return -1
        else return head->data;   // Otherwise, return the data of the head node
    }
};
