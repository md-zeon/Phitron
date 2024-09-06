/************************************************************
*  Problem: 912. Sort an Array
*  Link   : https://leetcode.com/problems/sort-an-array/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-09-05
*  ----------------------------------------------
*
*  Problem Description:
*  - Given an array of integers, sort the array in ascending order.
*  
*  Approach:
*  - This solution uses a min-heap to sort the array.
*  - Insert all elements of the array into the min-heap.
*  - Extract elements from the heap one by one and place them back into the array in sorted order.
*
*  Time Complexity : O(n log n)
*  - Inserting each element into the heap takes O(log n) time, so for n elements, it takes O(n log n).
*
*  Space Complexity: O(n)
*  - The heap stores n elements, so the space complexity is O(n).
*  
*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Insert an element into the min-heap
    void insertHeap(vector<int> &v, int x) {
        // Step 1: Insert the new element `x` at the end of the vector `v`
        v.push_back(x);
        int currIdx = v.size() - 1; // The index of the newly inserted element
        
        // Step 2: "Heapify up" to maintain the min-heap property
        // Keep comparing the inserted element with its parent and swapping if necessary
        while (currIdx != 0) {
            int parentIdx = (currIdx - 1) / 2; // Calculate the parent index
            if (v[currIdx] < v[parentIdx]) {   // If the current element is smaller than the parent
                swap(v[currIdx], v[parentIdx]); // Swap the elements
            } else {
                break;  // If the heap property is satisfied, stop
            }
            currIdx = parentIdx; // Move to the parent's index and continue heapifying up
        }
    }

    // Delete the root element (minimum) from the min-heap
    void deleteHeap(vector<int> &v) {
        if (v.size() == 0) return; // If the heap is empty, nothing to delete

        // Step 1: Replace the root (minimum element) with the last element in the heap
        v[0] = v[v.size() - 1];
        v.pop_back();  // Remove the last element (now at the root)

        int currIdx = 0; // Start heapifying down from the root

        // Step 2: "Heapify down" to restore the min-heap property
        while (currIdx < v.size()) {
            int leftIdx = (currIdx * 2) + 1;  // Index of the left child
            int rightIdx = (currIdx * 2) + 2; // Index of the right child
            int lastIdx = v.size() - 1;       // Last index of the heap

            // If both left and right children exist
            if (leftIdx <= lastIdx && rightIdx <= lastIdx) {
                // Find the smaller child and swap with the current node if necessary
                if (v[currIdx] > min(v[leftIdx], v[rightIdx])) {
                    if (v[leftIdx] <= v[rightIdx]) {
                        swap(v[currIdx], v[leftIdx]); // Swap with the left child if it is smaller
                        currIdx = leftIdx;  // Move to the left child index and continue heapifying down
                    } else {
                        swap(v[currIdx], v[rightIdx]); // Swap with the right child if it is smaller
                        currIdx = rightIdx; // Move to the right child index and continue heapifying down
                    }
                } else {
                    break; // If the current node is smaller than both children, stop
                }
            }
            // If only the left child exists
            else if (leftIdx <= lastIdx) {
                if (v[leftIdx] < v[currIdx]) { // Swap if the left child is smaller
                    swap(v[currIdx], v[leftIdx]);
                    currIdx = leftIdx; // Move to the left child index
                } else {
                    break; // Stop if the heap property is satisfied
                }
            }
            // If only the right child exists
            else if (rightIdx <= lastIdx) {
                if (v[rightIdx] < v[currIdx]) { // Swap if the right child is smaller
                    swap(v[currIdx], v[rightIdx]);
                    currIdx = rightIdx; // Move to the right child index
                } else {
                    break; // Stop if the heap property is satisfied
                }
            } else {
                break; // If no children exist, stop
            }
        }
    }

    // Function to sort the array using a min-heap
    vector<int> sortArray(vector<int>& nums) {
        vector<int> minHeap; // Create a min-heap (represented as a vector)

        // Step 1: Insert all elements from the array `nums` into the min-heap
        for (int i = 0; i < nums.size(); i++) {
            insertHeap(minHeap, nums[i]); // Insert element into the heap
        }

        // Step 2: Extract elements from the min-heap in sorted order
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = minHeap.front(); // The root of the heap is the smallest element
            deleteHeap(minHeap);  // Remove the smallest element from the heap
        }

        // Step 3: Return the sorted array
        return nums;
    }
};
