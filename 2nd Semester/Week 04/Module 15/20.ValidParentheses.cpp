/************************************************************
*  Problem: 20. Valid Parentheses
*  Link   : https://leetcode.com/problems/valid-parentheses/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------

*  Problem Description:
*  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
*  determine if the input string is valid. An input string is valid if:
*  1. Open brackets must be closed by the same type of brackets.
*  2. Open brackets must be closed in the correct order.
*  3. Every close bracket has a corresponding open bracket of the same type.
*
*  Constraints:
*  1 <= s.length <= 10^4
*  s consists of parentheses only '()[]{}'.
*
*  Approach:
*  - Use a stack data structure to match the open brackets with their corresponding closing brackets.
*  - Traverse through the string character by character.
*  - If an open bracket is encountered ('(', '{', '['), push it onto the stack.
*  - If a closing bracket is encountered, check if the stack is empty.
*    - If the stack is empty, return false (invalid).
*    - Otherwise, check if the top of the stack matches the current closing bracket.
*      - If it matches, pop the stack.
*      - If it doesn't match, return false.
*  - After processing all characters, if the stack is empty, the string is valid; otherwise, it is invalid.
*  
*  Time Complexity : O(n), where n is the length of the string s, since each character is processed once.
*  Space Complexity: O(n), in the worst case, the stack could contain all opening brackets.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else if ((c == ')' && st.top() == '(') ||
                            (c == '}' && st.top() == '{') ||
                            (c == ']' && st.top() == '[')) {
                                st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
