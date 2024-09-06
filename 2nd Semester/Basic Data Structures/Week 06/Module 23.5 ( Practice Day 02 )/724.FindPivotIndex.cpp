/************************************************************
*  Problem: 724. Find Pivot Index
*  Link   : https://leetcode.com/problems/find-pivot-index/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-06
*  ----------------------------------------------
*
*  Problem Description:
*  - Given an array of integers `nums`, calculate the pivot index of this array.
*  - The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the right of the index.
*  - If no such index exists, return -1.
*  - If there are multiple pivot indexes, return the left-most pivot index.
*
*  Approach:
*  - First, calculate the total sum of the array.
*  - Iterate through the array while keeping track of the cumulative left sum.
*  - For each element, calculate the right sum as `total_sum - left_sum - nums[i]`.
*  - If `left_sum == right_sum`, return the current index.
*  - If no pivot index is found, return -1.
*
*  Time Complexity : O(n), where n is the size of the array.
*  Space Complexity: O(1), since we are using only a few extra variables.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Step 1: Calculate the total sum of the array
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Step 2: Initialize the left sum to 0
        int left_sum = 0;

        // Step 3: Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the right sum as total_sum - left_sum - nums[i]
            int right_sum = total_sum - left_sum - nums[i];
            
            // Check if the left sum equals the right sum
            if (left_sum == right_sum) {
                return i;
            }

            // Update the left sum by adding the current element
            left_sum += nums[i];
        }

        // If no pivot index is found, return -1
        return -1;
    }
};
