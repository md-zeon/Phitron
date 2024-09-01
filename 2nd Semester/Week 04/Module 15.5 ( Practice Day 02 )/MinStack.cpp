/************************************************************
*  Problem: Min Stack
*  Link   : https://www.naukri.com/code360/problems/min-stack_3843991?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------
*
*  Problem Description:
*  Implement a stack that, in addition to the usual stack operations 
*  (push, pop, top), supports retrieving the minimum element in 
*  constant time (getMin).
*
*  Approach:
*  - We maintain two data structures:
*    1. A stack implemented using a singly linked list (`head` pointer)
*       to store the stack elements.
*    2. An additional stack (`min`) to keep track of the minimum 
*       elements. This stack only stores elements that are less than or 
*       equal to the current minimum, ensuring that the top of the `min` 
*       stack always holds the minimum element.
*  - When pushing an element, if it is smaller than or equal to the 
*    current minimum, we push it onto the `min` stack as well.
*  - When popping an element, if it is the same as the current minimum, 
*    we pop it from the `min` stack as well.
*  - The `getMin()` function simply returns the top of the `min` stack.
*
*  Time Complexity :
*  - push() : O(1)
*  - pop()  : O(1)
*  - top()  : O(1)
*  - getMin() : O(1)
*
*  Space Complexity: O(N), where N is the number of elements in the stack.
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

// Min Stack class implementation
class minStack
{
    Node* head;  // Pointer to the top of the stack
    int size;    // Number of elements in the stack
    stack<int> min;  // Stack to store the minimum elements

public:
    // Constructor to initialize an empty stack
    minStack() 
    { 
        head = NULL;  // Initially, the stack is empty
        size = 0;
    }
    
    // Function to push an element onto the stack
    void push(int num)
    {
        Node* newNode = new Node(num);  // Create a new node with the given data

        if(head == NULL) {  // If stack is empty
            head = newNode;  // The new node becomes the top
            min.push(num);   // Push the first element onto the min stack
        } else {
            newNode->next = head;  // Insert the new node at the top of the stack
            head = newNode;        // Update the head pointer to the new top
            if(min.top() >= num) {  // If the new element is smaller or equal to the current minimum
                min.push(num);      // Push it onto the min stack
            }
        }
        size++;  // Increment the stack size
    }
    
    // Function to pop the top element from the stack
    int pop()
    {
        if(head == NULL) {  // If stack is empty
            return -1;      // Return -1 to indicate underflow
        }

        if(min.top() == top()) {  // If the top element is the current minimum
            min.pop();  // Pop it from the min stack as well
        }

        Node* toDel = head;  // Store the current top node to delete
        int ele = toDel->data;  // Get the data from the top element
        head = head->next;  // Move the head pointer to the next node
        toDel->next = NULL;  // Disconnect the node to be deleted
        delete toDel;  // Free the memory
        size--;  // Decrement the stack size
        return ele;  // Return the popped element
    }
    
    // Function to return the top element of the stack
    int top()
    {
        if(size == 0) return -1;  // If stack is empty, return -1
        else return head->data;   // Otherwise, return the data of the top node
    }
    
    // Function to return the minimum element of the stack
    int getMin()
    {
        if(size == 0) return -1;  // If stack is empty, return -1
        else return min.top();    // Otherwise, return the top of the min stack
    }
};
