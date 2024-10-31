/************************************************************
*  Problem: 704. Binary Search
*  Link   : https://leetcode.com/problems/binary-search/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-11-01
*  ----------------------------------------------

*  Problem Description:
*  Given a sorted array of integers `nums` and an integer `target`,
*  write a function to search for `target` in `nums`. 
*  If `target` exists, then return its index. Otherwise, return -1.
*
*  Example:
*    Input: nums = [-1,0,3,5,9,12], target = 9
*    Output: 4
*  
*  Approach:
*  - Use binary search to find the target in the sorted array.
*  - Maintain two pointers (`si` for start index and `ei` for end index).
*  - Calculate the mid-point index and compare the middle element with the target.
*  - Adjust the pointers based on the comparison to narrow down the search range.
*  
*  Time Complexity : O(log n) – logarithmic time complexity due to halving the search space.
*  Space Complexity: O(1) – constant space complexity as we are using a fixed number of variables.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {-1, 0, 3, 5, 9, 12}; // Sample input array

class Solution {
public:
    // Function to search for the target in the sorted array
    int search(vector<int>& nums, int target) {
        int si = 0; // Start index
        int ei = nums.size() - 1; // End index
        
        // Loop until the start index is less than or equal to the end index
        while (si <= ei) {
            int mid = si + (ei - si) / 2; // Calculate the mid index
            if (nums[mid] == target) {
                return mid; // Target found, return its index
            } else if (nums[mid] > target) {
                ei = mid - 1; // Search in the left half
            } else {
                si = mid + 1; // Search in the right half
            }
        }
        return -1; // Target not found, return -1
    }
};
