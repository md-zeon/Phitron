/************************************************************
*  Problem: 2574. Left and Right Sum Differences
*  Link   : https://leetcode.com/problems/left-and-right-sum-differences/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-06
*  ----------------------------------------------
*
*  Problem Description:
*  - Given an array `nums`, return a new array `answer` where `answer[i]` is the absolute difference between the sum of elements to the left of the index `i` and the sum of elements to the right of index `i`.
*
*  Approach:
*  - First, calculate the total sum of the array.
*  - Iterate through the array while maintaining the left sum.
*  - Calculate the right sum as `total_sum - left_sum - nums[i]`.
*  - Store the absolute difference between `left_sum` and `right_sum` in the result array.
*
*  Time Complexity : O(n), where n is the size of the array.
*  Space Complexity: O(n), for the result array.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // Step 1: Calculate the total sum of the array
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Step 2: Initialize the result array and left sum
        vector<int> answer;
        int left_sum = 0;

        // Step 3: Iterate through the array to calculate the differences
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the right sum as total_sum - left_sum - nums[i]
            int right_sum = total_sum - left_sum - nums[i];
            
            // Calculate the absolute difference and store it in the result array
            answer.push_back(abs(left_sum - right_sum));

            // Update the left sum by adding the current element
            left_sum += nums[i];
        }

        // Step 4: Return the result array
        return answer;
    }
};
