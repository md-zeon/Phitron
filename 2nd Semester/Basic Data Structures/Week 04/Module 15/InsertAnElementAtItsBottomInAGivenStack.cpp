/************************************************************
*  Problem:  Insert An Element At Its Bottom In A Given Stack
*  Link   : https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------

*  Problem Description:
*  Given a stack and an integer element, insert the element at the bottom of the stack.
*  
*  Approach:
*  1. Use a temporary stack to hold all the elements from the original stack.
*  2. Once the original stack is empty, push the given element `x` onto the stack.
*  3. Push all elements from the temporary stack back onto the original stack.
*  
*  Time Complexity : O(N), where N is the number of elements in the stack.
*  Space Complexity: O(N), due to the additional temporary stack used.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h> 
using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    stack<int> temp;
    
    // Pop elements from myStack and push them to temp
    while(!myStack.empty()) {
        temp.push(myStack.top());
        myStack.pop();
    }
    
    // Push the new element at the bottom (myStack is now empty)
    myStack.push(x);
    
    // Pop elements from temp and push them back to myStack
    while(!temp.empty()) {
        myStack.push(temp.top());
        temp.pop();
    }

    return myStack;
}



/************************************************************
*  Problem:  Insert An Element At Its Bottom In A Given Stack
*  Link   : https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------

*  Problem Description:
*  Given a stack and an integer element, insert the element at the bottom of the stack.
*  
*  Approach:
*  1. Use recursion to pop all elements from the stack until it is empty.
*  2. Once the stack is empty, push the given element `x` onto the stack.
*  3. As the recursive calls return, push each popped element back onto the stack.
*  
*  Time Complexity : O(N), where N is the number of elements in the stack.
*  Space Complexity: O(N), due to the recursion stack.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& myStack, int x) {
    // Base case: if the stack is empty, push the element
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    // Recursively pop all elements
    int topElement = myStack.top();
    myStack.pop();

    // Insert `x` at the bottom of the stack
    insertAtBottom(myStack, x);

    // Push the popped element back onto the stack
    myStack.push(topElement);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    insertAtBottom(myStack, x);
    return myStack;
}
