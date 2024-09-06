/************************************************************
*  Problem: Reverse First K Elements of Queue
*  Link   : https://www.naukri.com/code360/problems/reverse-first-k-elements-of-queue_982771
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------
*
*  Problem Description:
*  Given a queue of integers, reverse the order of the first K 
*  elements of the queue, leaving the other elements in the same 
*  relative order. The goal is to modify the queue in-place and 
*  return the updated queue.
*
*  Approach:
*  - Use a stack to reverse the first K elements.
*  - First, dequeue K elements from the queue and push them onto 
*    the stack. This will reverse the order of these elements.
*  - Then, pop the elements from the stack and enqueue them back 
*    into the queue, which will place them in the reversed order 
*    at the front of the queue.
*  - Finally, dequeue the remaining elements from the queue and 
*    enqueue them back to maintain their original order.
*
*  Time Complexity : O(N)
*  - The total number of operations (push, pop, enqueue, dequeue) 
*    is linear with respect to the number of elements in the queue.
*
*  Space Complexity: O(K)
*  - The additional space used is for the stack that stores the 
*    first K elements.
*
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h> 
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    // Stack to reverse the first K elements
    stack<int> s;
    
    // Step 1: Dequeue the first K elements and push them onto the stack
    while (k--) {
        s.push(q.front());
        q.pop();
    }
    
    // Step 2: Enqueue the elements from the stack back into the queue
    queue<int> newQ;
    while (!s.empty()) {
        newQ.push(s.top());
        s.pop();
    }
    
    // Step 3: Enqueue the remaining elements in the original queue
    while (!q.empty()) {
        newQ.push(q.front());
        q.pop();
    }

    return newQ;
}
