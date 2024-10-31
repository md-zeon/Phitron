/************************************************************
*  Problem: 2529. Maximum Count of Positive Integer and Negative Integer
*  Link   : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-10-31
*  ----------------------------------------------

*  Problem Description:
*  Given a sorted integer array `nums`, find the maximum count between
*  the number of positive and negative integers in the array. The array
*  can include zeros, which are ignored in the count.
*  
*  Example:
*    Input: nums = [-3, -2, -1, 0, 0, 1, 2]
*    Output: 3 (since there are 3 negative numbers and 2 positive numbers)
*  
*  Approach:
*  - Traverse the array and count the number of positive and negative integers.
*  - Compare the counts and return the maximum of the two.
*  
*  Time Complexity : O(n) – single pass through `nums` to count positives and negatives.
*  Space Complexity: O(1) – constant space for counters.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {-3, -2, -1, 0, 0, 1, 2};

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0; // Counter for positive numbers
        int neg = 0; // Counter for negative numbers
        
        // Traverse the array and count positives and negatives
        for (int num : nums) {
            if (num < 0) neg++;     // Increment neg if number is negative
            else if (num > 0) pos++; // Increment pos if number is positive
        }

        // Return the maximum count between positives and negatives
        return max(pos, neg);
    }
};



/************************************************************
*  Problem: 2529. Maximum Count of Positive Integer and Negative Integer
*  Link   : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-10-31
*  ----------------------------------------------

*  Problem Description:
*  Given a sorted integer array `nums`, find the maximum count between
*  the number of positive and negative integers in the array. The array
*  can include zeros, which are ignored in the count.
*  
*  Optimized Approach (Manual Binary Search):
*  - Use binary search to find the index of the first non-negative element
*    and the first positive element.
*  - Calculate the count of negative and positive numbers based on these indices.
*  
*  Time Complexity : O(log n) – two binary searches.
*  Space Complexity: O(1) – constant space.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/


class Solution2 {
public:
    // Custom binary search to find the first element >= target
    int findFirstGreaterOrEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int index = nums.size();  // Default to size if target is not found
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                index = mid; // Potential answer, move left to find the first occurrence
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index;
    }

    int maximumCount(vector<int>& nums) {
        // Find the first index of a non-negative number
        int firstNonNegative = findFirstGreaterOrEqual(nums, 0);
        
        // Find the first index of a positive number
        int firstPositive = findFirstGreaterOrEqual(nums, 1);
        
        // Calculate counts
        int negCount = firstNonNegative;             // Count of negatives is up to the first non-negative index
        int posCount = nums.size() - firstPositive;  // Count of positives from first positive index to the end

        // Return the maximum count between positives and negatives
        return max(negCount, posCount);
    }
};
