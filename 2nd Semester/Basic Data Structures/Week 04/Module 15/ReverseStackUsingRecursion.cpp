/************************************************************
*  Problem: reverse a stack using recursion
*  Link   : https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------
*  
*  Problem Description:
*  The task is to reverse a stack using recursive techniques 
*  without using any additional data structures other than 
*  auxiliary stacks. The solution must leverage the power 
*  of recursion to achieve this.
*
*  Approach:
*  - This approach uses recursion to insert elements at the bottom of the stack.
*  - First, we pop all elements recursively until the stack is empty.
*  - Then, we insert the popped elements at the bottom of the stack one by one.
*  - This effectively reverses the stack as the original top element becomes the bottom element.
*  
*  Time Complexity : O(N^2), where N is the number of elements in the stack.
*                    This is due to the repeated insertion of elements at the bottom of the stack.
*  Space Complexity: O(N) due to the recursion stack.
*  
*  Platform: Naukri Code360 (Coding Ninja)
*  Status  : Solved
************************************************************/



#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &s, int ele) {
    // Base case: if the stack is empty, push the element
    if (s.empty()) {
        s.push(ele);
        return;
    }
    // Pop the top element from the stack
    int topElement = s.top();
    s.pop();
    // Recursively insert the element at the bottom of the stack
    insertAtBottom(s, ele);
    // Push the popped element back onto the stack
    s.push(topElement);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &s) {
    // Base case: if the stack is empty, return
    if (s.empty()) {
        return;
    }
    // Pop the top element from the stack
    int topElement = s.top();
    s.pop();
    // Recursively reverse the remaining stack
    reverseStack(s);
    // Insert the popped element at the bottom of the reversed stack
    insertAtBottom(s, topElement);
}



// solution 02


/************************************************************
*  Problem: reverse a stack using recursion
*  Link   : https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------
*  
*  Problem Description:
*  The task is to reverse a stack using recursive techniques 
*  without using any additional data structures other than 
*  auxiliary stacks. The solution must leverage the power 
*  of recursion to achieve this.
*
*  Approach (2):
*  - In this approach, recursion is combined with a temporary stack.
*  - We recursively pop all elements from the stack.
*  - After that, we use a temporary stack to reorder the elements.
*  - The top element of the original stack is pushed onto the temporary stack, 
*    and then all elements are moved back to the original stack.
*  
*  Time Complexity : O(N^2), where N is the number of elements in the stack.
*                    This is due to the operations needed to move elements 
*                    between the original and temporary stack.
*  Space Complexity: O(N) due to the recursion stack and temporary stack.
*  
*  Platform: Naukri Code360 (Coding Ninja)
*  Status  : Solved
************************************************************/



// Function to reverse the stack using recursion and a temporary stack
void reverseStack(stack<int> &s) {
    // Base case: if the stack is empty, return
    if (s.empty()) {
        return;
    }
    // Pop the top element from the stack
    int topElement = s.top();
    s.pop();
    // Recursively reverse the remaining stack
    reverseStack(s);
    // Create a temporary stack to hold the reversed elements
    stack<int> cp;
    // Pop all elements from the original stack and push them onto the temporary stack
    while (!s.empty()) {
        cp.push(s.top());
        s.pop();
    }
    // Push the top element onto the temporary stack
    cp.push(topElement);
    // Pop all elements from the temporary stack and push them back onto the original stack
    while (!cp.empty()) {
        s.push(cp.top());
        cp.pop();
    }
}