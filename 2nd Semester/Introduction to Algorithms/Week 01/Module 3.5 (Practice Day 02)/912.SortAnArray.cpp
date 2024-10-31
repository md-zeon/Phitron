/************************************************************
*  Problem: 912. Sort an Array
*  Link   : https://leetcode.com/problems/sort-an-array/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-11-01
*  ----------------------------------------------

*  Problem Description:
*  Given an array of integers `nums`, sort the array in ascending order 
*  and return it.
*  
*  Example:
*    Input: nums = [5,2,3,1]
*    Output: [1,2,3,5]
*  
*  Approach:
*  - Implement the Merge Sort algorithm, which divides the array 
*    into two halves, recursively sorts them, and then merges the 
*    sorted halves.
*  - The merging step ensures that the elements are combined in 
*    sorted order.
*  
*  Time Complexity : O(n log n) – the array is divided in half at 
*                    each level of recursion, and merging takes linear time.
*  Space Complexity: O(n) – additional space is required for the temporary
*                    array used in merging.
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to merge two sorted halves of the array
    void merge(vector<int> &v, int si, int mid, int ei) {
        vector<int> temp; // Temporary array to hold merged values
        int i = si; // Pointer for the left half
        int j = mid + 1; // Pointer for the right half
        
        // Merging the two halves
        while (i <= mid && j <= ei) {
            if (v[i] < v[j]) {
                temp.push_back(v[i]); // Add smaller element from the left half
                i++;
            } else {
                temp.push_back(v[j]); // Add smaller element from the right half
                j++;
            }
        }

        // Add remaining elements from the left half
        while (i <= mid) {
            temp.push_back(v[i]);
            i++;
        }

        // Add remaining elements from the right half
        while (j <= ei) {
            temp.push_back(v[j]);
            j++;
        }

        // Copy the sorted elements back into the original array
        for (int i = si, k = 0; k < temp.size(); i++, k++) {
            v[i] = temp[k];
        }
        temp.clear(); // Clear temporary array
    }

    // Recursive function to perform merge sort
    void mergeSort(vector<int> &v, int si, int ei) {
        if (si >= ei) { // Base case
            return;
        }
        int mid = si + (ei - si) / 2; // Calculate mid index
        mergeSort(v, si, mid); // Sort the left half
        mergeSort(v, mid + 1, ei); // Sort the right half
        merge(v, si, mid, ei); // Merge the sorted halves
    }

    // Function to sort the array
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1); // Start merge sort on the entire array
        return nums; // Return the sorted array
    }
};
