/************************************************************
*  Problem: 88. Merge Sorted Array
*  Link   : https://leetcode.com/problems/merge-sorted-array/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-11-01
*  ----------------------------------------------

*  Problem Description:
*  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*  The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that 
*  nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.

*  Example:
*    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
*    Output: [1,2,2,3,5,6]
*  
*  Approach:
*  - Use three pointers to merge the two arrays from the end:
*    - `i` for the last initialized element of nums1
*    - `j` for the last element of nums2
*    - `k` for the last position in nums1.
*  - Compare elements and place the larger one at the `k` position in nums1.
*  - If any elements remain in nums2, copy them to nums1.
*  
*  Time Complexity : O(m + n) – single pass through both arrays.
*  Space Complexity: O(1) – in-place merging.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> temp; // Temporary vector to hold merged result
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }    
        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }
        nums1.clear(); // Clear nums1 to prepare for merged result
        nums1 = temp; // Assign merged result back to nums1
        temp.clear(); // Clear temporary vector
    }
};

/************************************************************
*  Problem: 88. Merge Sorted Array
*  Link   : https://leetcode.com/problems/merge-sorted-array/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-11-01
*  ----------------------------------------------

*  Problem Description:
*  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*  The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that 
*  nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.

*  Example:
*    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
*    Output: [1,2,2,3,5,6]
*  
*  Approach:
*  - Use three pointers to merge the two arrays from the end:
*    - `i` for the last initialized element of nums1
*    - `j` for the last element of nums2
*    - `k` for the last position in nums1.
*  - Compare elements and place the larger one at the `k` position in nums1.
*  - If any elements remain in nums2, copy them to nums1.
*  
*  Time Complexity : O(m + n) – single pass through both arrays.
*  Space Complexity: O(1) – in-place merging.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for the last element in nums1's initialized part
        int j = n - 1; // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the last position in nums1

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i]; // Place larger element in the end
                i--; // Move pointer in nums1
            } else {
                nums1[k] = nums2[j]; // Place element from nums2
                j--; // Move pointer in nums2
            }
            k--; // Move the position in nums1
        }

        // Copy remaining elements from nums2, if any
        while (j >= 0) {
            nums1[k] = nums2[j]; // Place remaining elements from nums2
            j--;
            k--;
        }
        // No need to copy remaining nums1 elements as they are already in place
    }
};
