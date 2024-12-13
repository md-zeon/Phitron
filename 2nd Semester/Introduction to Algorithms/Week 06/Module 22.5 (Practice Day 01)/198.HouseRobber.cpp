/************************************************************
*  Problem: 198. House Robber
*  Link   : https://leetcode.com/problems/house-robber/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-13
*  ----------------------------------------------
*
*  Problem Description:
*  You are a professional robber planning to rob houses along a street. 
*  Each house has a certain amount of money stashed, the only constraint is that 
*  adjacent houses have security systems connected, and it will automatically 
*  contact the police if two adjacent houses are robbed on the same night.
*
*  Approach:
*  The problem can be solved using dynamic programming (DP). 
*  We can decide whether to rob the current house or skip it based on the maximum money we can rob.
*  1. If we rob the current house, we must skip the previous house, and add the money of the current house to the result of the optimal solution for previous non-adjacent houses.
*  2. If we skip the current house, the optimal solution is the same as the optimal solution for the previous house.
*  3. We use a DP table or two variables to track the maximum money robbed up to the current index.
*  
*  Time Complexity : O(n) where n is the number of houses. We only iterate through the list once.
*  Space Complexity: O(n) for the DP array in the recursive approach, or O(1) for the optimized iterative solution using two variables.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function for recursive approach with memoization
    int rec(vector<int>& nums, int i, vector<int>& dp) {
        if (i < 0) return 0; // Base case: No houses left to rob, return 0
        if (dp[i] != -1) return dp[i]; // If the result for this index is already calculated, return it

        // Decide whether to rob the current house (nums[i]) or skip it
        // If we rob, skip the previous house (i-2), otherwise, skip the current house (i-1)
        return dp[i] = max(nums[i] + rec(nums, i - 2, dp), rec(nums, i - 1, dp));
    }

    // Main function for recursive approach
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // Initialize the DP array with -1 (indicating uncalculated values)
        return rec(nums, n - 1, dp); // Start from the last house
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Base cases
        if (n == 1) return nums[0]; // Only one house, rob it
        if (n == 2) return max(nums[0], nums[1]); // Two houses, rob the one with more money

        // Two variables to store the maximum money robbed up to the previous house
        int prev2 = nums[0]; // Money robbed when considering only the first house
        int prev1 = max(nums[0], nums[1]); // Money robbed when considering the first two houses

        // Iteratively calculate the maximum money robbed by deciding whether to rob each house
        for (int i = 2; i < n; i++) {
            int current = max(nums[i] + prev2, prev1); // Max money by robbing or skipping the current house
            prev2 = prev1; // Move prev1 to prev2 for the next iteration
            prev1 = current; // Update prev1 to the current maximum
        }

        return prev1; // Return the maximum money robbed after processing all houses
    }
};
