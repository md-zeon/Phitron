/************************************************************
*  Problem: 268. Missing Number
*  Link   : https://leetcode.com/problems/missing-number/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-10-31
*  ----------------------------------------------

*  Problem Description:
*  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
*  find the one number that is missing from this array.
*
*  Example:
*    Input: nums = [9,6,4,2,3,5,7,0,1]
*    Output: 8
*  
*  Approach (Solution):
*  - Sort the array and use binary search to find the missing number.
*  - Increment a counter starting from 0 until the number is not found in the array.
*  
*  Time Complexity : O(n log n) – due to sorting the array.
*  Space Complexity: O(1) – constant space.
*  
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};

class Solution {
public:
    // Function to perform binary search in a sorted array
    bool binarySearch(vector<int> nums, int target) {
        int si = 0; // Start index
        int ei = nums.size() - 1; // End index
        while (si <= ei) {
            int mid = si + (ei - si) / 2; // Calculate mid index
            if (nums[mid] == target) {
                return true; // Target found
            } else if (nums[mid] > target) {
                ei = mid - 1; // Search in the left half
            } else {
                si = mid + 1; // Search in the right half
            }
        }
        return false; // Target not found
    }

    // Function to find the missing number
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array
        int num = 0; // Initialize missing number counter
        // Increment until the number is found
        while (binarySearch(nums, num)) {
            num++;
        }
        return num; // Return the missing number
    }
};

/************************************************************
*  Approach (Solution2):
*  - Calculate the expected sum of numbers from 0 to n using the formula: 
*    `expectedSum = n * (n + 1) / 2`.
*  - Calculate the actual sum of the array elements.
*  - The difference between `expectedSum` and `actualSum` gives the missing number.
*  
*  Time Complexity : O(n) – single pass through `nums` to get the sum.
*  Space Complexity: O(1) – constant space.
*  
*  Status  : Solved
************************************************************/

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        int expectedSum = n * (n + 1) / 2; // Calculate expected sum from 0 to n
        int actualSum = 0; // Initialize actual sum

        // Calculate the actual sum of the elements in the array
        for (int num : nums) {
            actualSum += num; // Add each element to the actual sum
        }

        // The missing number is the difference between expected and actual sum
        return expectedSum - actualSum; // Return the missing number
    }
};
