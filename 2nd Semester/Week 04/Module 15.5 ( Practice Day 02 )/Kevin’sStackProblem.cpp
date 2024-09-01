/************************************************************
*  Problem: Kevin's Stack Problem
*  Link   : https://www.naukri.com/code360/problems/kevin-s-stack-problem_1169465
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------
*
*  Problem Description:
*  Given a string `s`, reverse the string using a stack. The stack 
*  operations will be used to reverse the order of characters in 
*  the string. The task is to return the reversed string.
*
*  Approach:
*  - Iterate through the string and push each character onto the stack.
*  - After all characters are pushed, pop each character from the stack 
*    and append it to the resulting string. This will result in reversing 
*    the order of characters.
*  - The stack data structure follows a Last In, First Out (LIFO) 
*    principle, so when we pop characters from the stack, they will 
*    be in reverse order of how they were pushed.
*
*  Time Complexity : O(N)
*  - We iterate through the string to push the characters onto the stack, 
*    and then iterate again to pop them off. Therefore, the time complexity 
*    is O(N), where N is the length of the string.
*
*  Space Complexity: O(N)
*  - The stack requires O(N) space to store the characters.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h> 
using namespace std;

string kevinStackProblem(string &s)
{
    // Stack to hold characters of the string
    stack<char> st;

    // Step 1: Push all characters of the string onto the stack
    for (char c : s) {
        st.push(c);
    }

    // Clear the string to rebuild it in reverse
    s = "";

    // Step 2: Pop all characters from the stack and append them to the string
    while (!st.empty()) {
        s += st.top();  // Append the top character to the string
        st.pop();       // Remove the top character from the stack
    }

    return s;  // Return the reversed string
}
