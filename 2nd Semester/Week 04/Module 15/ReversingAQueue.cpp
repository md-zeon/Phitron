/************************************************************
*  Problem: Reversing a Queue
*  Link   : https://www.naukri.com/code360/problems/reversing-a-queue_982934?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------

*  Problem Description:
*  Given a queue of integers, the goal is to reverse the elements of the queue using standard queue and stack operations.
*
*  Approach:
*  1. Push all elements of the queue into a stack. This reverses the order of elements.
*  2. Pop all elements from the stack and push them back into the queue.
*  
*  Time Complexity : O(N), where N is the number of elements in the queue.
*  Space Complexity: O(N), since we are using an additional stack to hold all the elements.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h> 
using namespace std;

queue<int> reverseQueue(queue<int> q) {
    // Write your code here.
    stack<int> s;

    // Step 1: Transfer all elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Transfer all elements back from the stack to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}
