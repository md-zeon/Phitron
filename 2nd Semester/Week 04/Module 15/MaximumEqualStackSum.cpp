/************************************************************
*  Problem: Maximum Equal Stack Sum
*  Link   : https://www.naukri.com/code360/problems/maximum-equal-stack-sum_1062571?leftPanelTabValue=PROBLEM
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-01
*  ----------------------------------------------

*  Problem Description:
*  Given three stacks of integers, the goal is to find the maximum sum that can be obtained by popping elements from the top of the stacks so that the sum of the elements in all three stacks becomes equal.
*  
*  Approach:
*  1. Calculate the sum of elements in all three stacks.
*  2. Compare the sums of the stacks. If the sums are not equal, pop elements from the stack with the maximum sum.
*  3. Repeat this process until all three sums become equal.
*  
*  Time Complexity : O(N1 + N2 + N3), where N1, N2, and N3 are the number of elements in the three stacks.
*  Space Complexity: O(1), as we are not using any extra space other than a few variables to store the sums.
*  
*  Platform: Coding Ninja
*  Status  : Solved
************************************************************/


#include <bits/stdc++.h>
using namespace std;

// Helper function to calculate the sum of elements in a stack
int getSum(stack<int> s) {
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    return sum;
}

// Function to find the maximum possible equal sum of the three stacks
int maxSum(stack<int> &s1, stack<int> &s2, stack<int> &s3) {
    // Calculate the initial sum of elements in each stack
    int sum1 = getSum(s1);
    int sum2 = getSum(s2);
    int sum3 = getSum(s3);

    // Loop until all three sums become equal
    while (true) {
        // If all sums are equal, break the loop
        if (sum1 == sum2 && sum2 == sum3) break;

        // Pop elements from the stack with the maximum sum
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= s1.top();
            s1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= s2.top();
            s2.pop();
        } else {
            sum3 -= s3.top();
            s3.pop();
        }
    }
    // Return the maximum possible equal sum
    return sum1;
}
