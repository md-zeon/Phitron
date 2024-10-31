/************************************************************
*  Problem: 2089. Find Target Indices After Sorting Array
*  Link   : https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-10-31
*  ----------------------------------------------

*  Problem Description:
*  Given an array `nums` and a target integer `target`, return the 
*  indices of all occurrences of `target` in `nums` after sorting 
*  `nums` in non-decreasing order.

*  Approach:
*  - Sort the array `nums` in non-decreasing order.
*  - Traverse through the sorted array and collect indices where the element equals `target`.
*  
*  Time Complexity : O(n log n) – due to the sorting step, where `n` is the number of elements in `nums`.
*  Space Complexity: O(1) – assuming `indices` is the output and doesn't count towards extra space.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {1, 2, 5, 2, 3};

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> indices;          // To store indices of target occurrences
        sort(nums.begin(), nums.end()); // Sort the array in non-decreasing order

        // Traverse sorted array to find target indices
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {     // If the element equals target
                indices.push_back(i);    // Store the index
            }
        }
        
        return indices; // Return the list of target indices
    }
};



/************************************************************
*  Problem: 2089. Find Target Indices After Sorting Array
*  Link   : https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-10-31
*  ----------------------------------------------

*  Problem Description:
*  Given an array `nums` and a target integer `target`, return the 
*  indices of all occurrences of `target` in `nums` after sorting 
*  `nums` in non-decreasing order.

*  Optimized Approach (Counting):
*  - Count elements less than `target` (countLess) to determine where 
*    the first occurrence of `target` would appear in sorted order.
*  - Count elements equal to `target` (countEqual) to determine how many
*    occurrences of `target` should be added.
*  - The indices of `target` will start from `countLess` and continue for
*    `countEqual` positions.
*  
*  Time Complexity : O(n) – single pass through `nums` for counting.
*  Space Complexity: O(1) – assuming the output does not count as extra space.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

class Solution2 {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int countLess = 0;  // Count of numbers less than target
        int countEqual = 0; // Count of numbers equal to target

        // Single pass to count elements less than and equal to target
        for (int num : nums) {
            if (num < target) countLess++;
            else if (num == target) countEqual++;
        }

        // Fill the result vector with indices where target would appear
        vector<int> indices;
        for (int i = 0; i < countEqual; i++) {
            indices.push_back(countLess + i);
        }
        
        return indices; // Return the list of target indices
    }
};
