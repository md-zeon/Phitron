/************************************************************
*  Problem: 746. Min Cost Climbing Stairs
*  Link   : https://leetcode.com/problems/min-cost-climbing-stairs/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-13
*  ----------------------------------------------
*  Problem Description:
*  You are given an integer array `cost` where `cost[i]` is the cost of the i-th step on a staircase. 
*  Once you pay the cost, you can either climb one or two steps.
*  You need to find the minimum cost to reach the top of the staircase.
*
*  Approach:
*  Two approaches are implemented:
*  1. Top-Down Approach using Recursion with Memoization.
*  2. Bottom-Up Approach using a DP Table.
*  
*  Time Complexity : O(n) for both approaches
*  Space Complexity: O(n) for Top-Down (including recursion stack), O(n) for Bottom-Up
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Top-Down Approach: Recursion with Memoization
class Solution {
public:
    // Recursive function to calculate minimum cost to reach step `n`
    int rec(vector<int> &cost, int n, vector<int> &dp) {
        // Base cases: Cost to reach the 0th or 1st step is the step's cost
        if (n == 0 || n == 1) {
            return cost[n];
        }

        // If already computed, return the stored result
        if (dp[n] != -1) {
            return dp[n];
        }

        // Recursive calls: Calculate the cost of reaching `n-1` and `n-2`
        int op1 = rec(cost, n - 1, dp);
        int op2 = rec(cost, n - 2, dp);

        // Store the minimum cost to reach step `n` in dp array
        return dp[n] = min(op1, op2) + cost[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1); // Initialize DP array with -1 (uncomputed)

        // Calculate the minimum cost to reach the last two steps
        int last = rec(cost, n - 1, dp);
        int secondLast = rec(cost, n - 2, dp);

        // Return the minimum cost to reach the top
        return min(last, secondLast);
    }
};

// Bottom-Up Approach: Iterative Dynamic Programming
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n); // DP array to store minimum cost to reach each step

        // Base cases: Cost to reach the 0th and 1st steps is their respective costs
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill the DP array iteratively
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]; // Transition relation
        }

        // Return the minimum cost to reach the top
        return min(dp[n - 1], dp[n - 2]);
    }
};
