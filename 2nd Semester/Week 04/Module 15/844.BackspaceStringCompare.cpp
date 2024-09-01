/************************************************************
*  Problem: 844. Backspace String Compare
*  Link   : https://leetcode.com/problems/backspace-string-compare/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------

*  Problem Description:
*  Given two strings s and t, return true if they are equal when both are typed into empty text editors.
*  '#' means a backspace character.
*  
*  Approach:
*  1. Use two stacks to simulate typing the strings, accounting for backspaces.
*  2. Push characters onto the stack when a normal character is encountered.
*  3. Pop characters from the stack when a backspace ('#') is encountered.
*  4. Compare the resulting stacks to check if both strings are equal.
*  
*  Time Complexity : O(N + M), where N and M are the lengths of the strings s and t.
*  Space Complexity: O(N + M), due to the use of two stacks.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;

        // Process string s
        for (char c : s) {
            if (c == '#') {
                if (!s1.empty()) s1.pop();  // Simulate backspace
            } else {
                s1.push(c);  // Add character to stack
            }
        }

        // Process string t
        for (char c : t) {
            if (c == '#') {
                if (!s2.empty()) s2.pop();  // Simulate backspace
            } else {
                s2.push(c);  // Add character to stack
            }
        }

        // Compare the resulting stacks
        return s1 == s2;
    }
};
